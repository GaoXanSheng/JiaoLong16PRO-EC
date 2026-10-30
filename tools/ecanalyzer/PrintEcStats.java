// @category EC
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class PrintEcStats extends GhidraScript {
    public void run() throws Exception {
        int n = 0;
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            Function f = it.next();
            if (n < 12) {
                println(f.getEntryPoint() + " " + f.getName());
            }
            n++;
        }
        println("total functions: " + n);
    }
}
