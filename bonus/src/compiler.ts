import { default as createCompiler } from "../public/build/asm.js";

export class CompilationError extends Error {
    public errors: string[];

    constructor(errors: string[]) {
        super(errors[0]);
        this.errors = errors;
        Object.setPrototypeOf(this, CompilationError.prototype);
    }
}

export default async () => {
    let handleStdout = (text) => {
        console.log(text);
    };
    let handleStderr = (text) => {
        console.error(text);
    };
    let defaultStdoutHandler = handleStdout;
    let defaultStderrHandler = handleStderr;

    const compiler = await createCompiler({
        print: (text) => { handleStdout(text); },
        printErr: (text) => { handleStderr(text) }
    });

    const compile_fd = compiler.cwrap('compile_fd', 'number', ['number', 'string', 'string']);
    const write = compiler.cwrap('write', 'number', ['number', 'string', 'number']);

    return {

        compileString(input: string) {
            let output = "";
            let errors = [];
            handleStdout = (text) => { output += text + "\0" };
            handleStderr = (text) => { errors.push(text); };
            if (compile_fd(1, "input", input) < 0)
                throw new CompilationError(errors);
            write(1, "\n", 1);
            handleStdout = defaultStdoutHandler;
            handleStderr = defaultStderrHandler;
            return output.slice(0, output.length - 1);
        }

    };
};