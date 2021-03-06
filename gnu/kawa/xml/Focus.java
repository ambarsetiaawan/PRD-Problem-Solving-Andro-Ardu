package gnu.kawa.xml;

import gnu.bytecode.ClassType;
import gnu.bytecode.Method;
import gnu.expr.Compilation;
import gnu.lists.TreePosition;
import gnu.math.IntNum;

public final class Focus extends TreePosition {
    public static final ClassType TYPE;
    static ThreadLocal current;
    static final Method getCurrentFocusMethod;
    IntNum contextPosition;
    public long position;

    static {
        current = new ThreadLocal();
        TYPE = ClassType.make("gnu.kawa.xml.Focus");
        getCurrentFocusMethod = TYPE.getDeclaredMethod("getCurrent", 0);
    }

    public static Focus getCurrent() {
        Focus obj = current.get();
        if (obj == null) {
            obj = new Focus();
            current.set(obj);
        }
        return obj;
    }

    public static void compileGetCurrent(Compilation comp) {
        comp.getCode().emitInvoke(getCurrentFocusMethod);
    }
}
