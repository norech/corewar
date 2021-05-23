import { default as createVM } from "../public/build/corewar.js";
import { createWasmWrapper, WasmWrapper } from "./WasmWrapper.js";

export class Program {
    memPtr: number;
    championsPtr: number[];
    vm: WasmWrapper<any>;

    private alloc_program_memory: () => number;
    private free_program_memory: (ptr: number) => void;
    private alloc_champion: () => number;
    private create_champion_from_bytes: (champPtr: number, memPtr: number,
        input: string, inputSize: number) => number;
    private move_to_champion_pos: (memPtr: number, champPtr: number) => number;
    private free_champion: (ptr: number) => void;
    private next_step: (memPtr: number, champPtr: number[]) => number;

    _wrapFunctions(vm: WasmWrapper<any>)
    {
        this.alloc_program_memory = vm.module.cwrap('alloc_program_memory',
            'number', []);
        this.free_program_memory = vm.module.cwrap('free_program_memory',
            'void', ['number']);
        this.create_champion_from_bytes = vm.module.cwrap('create_champion_from_bytes',
            'number', ['number', 'number', 'string', 'number']);
        this.alloc_champion = vm.module.cwrap('alloc_champion',
            'number', []);
        this.free_champion = vm.module.cwrap('free_champion',
            'void', ['number']);
        this.next_step = vm.module.cwrap('next_step',
            'number', ['number', 'array']);
        this.move_to_champion_pos = vm.module.cwrap('move_to_champion_pos',
            'number', ['number', 'number']);
    }

    constructor(vm: WasmWrapper<any>) {
        this.vm = vm;
        this._wrapFunctions(vm);

        const memPtr = this.alloc_program_memory();
        if (memPtr == 0)
            throw new Error("can't alloc program memory");
        this.memPtr = memPtr;
        this.championsPtr = [];
    }

    addChampion(bytes: string) {
        const champPtr = this.alloc_champion();
        if (champPtr == 0)
            throw new Error("can't alloc memory for champion");
        if (this.create_champion_from_bytes(champPtr, this.memPtr, bytes, bytes.length) < 0)
            throw new Error("can't create champion");
        this.championsPtr.push(champPtr);
        this.move_to_champion_pos(this.memPtr, this.championsPtr[0]);
    }

    destroy() {
        for (const champion of this.championsPtr) {
            this.free_champion(champion);
        }
        this.free_program_memory(this.memPtr);
    }

    nextStep() {
        let output = "";
        this.vm.handleStdout = (text) => { output += text + "\n"; };
        if (this.next_step(this.memPtr, this.championsPtr) < 0)
            throw new Error("step failed");
        this.vm.handleStdout = this.vm.defaultStdoutHandler;
        return (output);
    }
}

export async function create(): Promise<Program> {
    const vm = await createWasmWrapper(createVM);
    return new Program(vm);
}