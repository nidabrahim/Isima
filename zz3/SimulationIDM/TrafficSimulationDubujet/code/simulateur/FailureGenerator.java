package simulateur;

import model.AtomicModel;
import exception.DEVS_Exception;
import types.DEVS_Enum;
import java.util.*;

public class FailureGenerator extends AtomicModel {
	// Definition of S : no state variable since there is only one single possible state
	
	// Additional attribute necessary for random number generation
	Random rd;
	
	public FailureGenerator(String name, String desc) {
		super(name, desc);
		
		// Definition of the output port (for Y):
		// the name of the port is xxx.out if the name of the model is xxx
		// the value sent out is a command: "Failure"
		String[] commands = {"Failure"};
		addOutputPortStructure(new DEVS_Enum(commands), this.getName()+".OUT", "My single output port");
		
		// No input port : X = {}
		
		// No state initialization: the state will always be the same implicit one
		
		// Initialization of the additional attribute
		rd = new Random();
	}

	public void deltaInt() {
		// Nothing to say: we always return to the same implicit state
	}

	public double ta() {
		// The real value returned is in [4, 20]
		return ((int)(rd.nextDouble()*16) + 4.0);
	}

	public void lambda() throws DEVS_Exception {
		if(rd.nextInt(100)+1 < 50) {
			setOutputPortData(this.getName()+".OUT", "Failure");
		}
	}

	public void deltaExt(double e) throws DEVS_Exception {
		// Not defined, since there is no input
	}
}