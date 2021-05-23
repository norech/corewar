export interface WasmWrapper<T> {
    handleStdout: (line: string) => void;
    handleStderr: (line: string) => void;
    defaultStdoutHandler: (line: string) => void;
    defaultStderrHandler: (line: string) => void;
    module: T;
}

export async function createWasmWrapper<T>(createFunc: (options: any) => Promise<any>)
{
    const wrapper: Partial<WasmWrapper<T>> = {
        defaultStdoutHandler: (text: string) => { console.log(text); },
        defaultStderrHandler: (text: string) => { console.error(text); },
    }
    wrapper.handleStdout = wrapper.defaultStdoutHandler;
    wrapper.handleStderr = wrapper.defaultStderrHandler;

    wrapper.module = await createFunc({
        print: (line: string) => { wrapper.handleStdout(line); },
        printErr: (line: string) => { wrapper.handleStderr(line) }
    });
    return wrapper as WasmWrapper<T>;
}