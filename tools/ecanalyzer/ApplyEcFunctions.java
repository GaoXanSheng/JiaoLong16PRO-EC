// @category EC
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import java.io.BufferedReader;
import java.io.FileReader;

public class ApplyEcFunctions extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String csv = args[0];
        int region = Integer.parseInt(args[1]);
        BufferedReader br = new BufferedReader(new FileReader(csv));
        try {
            br.readLine();
            String line;
            while ((line = br.readLine()) != null) {
                String[] f = line.split(",");
                int rowRegion = Integer.parseInt(f[0]);
                if (region >= 0 && rowRegion != region) {
                    continue;
                }
                if (region < 0 && rowRegion > 1) {
                    continue;
                }
                Address addr = toAddr(Long.parseLong(f[2].substring(2), 16));
                String name = f[4];
                Function func = getFunctionAt(addr);
                if (func == null) {
                    func = createFunction(addr, name);
                }
                if (func != null) {
                    try {
                        func.setName(name, SourceType.USER_DEFINED);
                    } catch (Exception e) {
                    }
                }
                try {
                    createLabel(addr, name, true, SourceType.USER_DEFINED);
                } catch (Exception e) {
                }
            }
        } finally {
            br.close();
        }
        println("applied region " + region + ", total functions: "
                + currentProgram.getFunctionManager().getFunctionCount());
    }
}
