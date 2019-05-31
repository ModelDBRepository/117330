    //The following is C code that was used in a MatLab mex file to implement the neuron model.
    //The differential equations can be solved by various means,
    // where the input is STIM and the output is Y

    //3D simplified Hodgkin-Huxley neuron model with slow Na inactivation gate 
    //Parameters to implement model in Figure 11 of Lundstrom et al., J Comp Neurosci

	// Parameters:
	cm = 1;		// uF / cm2
	Gl = 15;   // mS/cm2
	Gk = 36;  
	Gna = 50; 
	El = -54;   // mV
	Ek = -77;	
	Ena = 50;	
   		
	//Differential equations
	mVh = -40;
    mk =  7;
    nVh = -30;
    nk = 5;
    Cbase = 50;
    Camp = 2000;
    Vmax = -40;
    sig = 5;
    
	ntau= 3;
    ninf = 1.0 / (1+exp( (nVh - y[0])/nk) );
    minf  = 1.0 / (1+exp( (mVh - y[0])/mk) );
    
    h = .89 - 1.1*y[1];
    s = .89 - 1.1*y[2];
    
    //time constant for slow Na inactivation
    stau= Cbase + Camp*exp(-pow(Vmax - y[0],2)/pow(sig,2));
           
    //stim is the variable that passes the stimulus value for each time t
    dy[0] = -1*(Gl*(y[0] - El) + Gk*pow(y[1],4)*(y[0] - Ek) + Gna*pow(minf,3)*h*s*(y[0] - Ena))/cm + stim/cm;
	dy[1] = (ninf - y[1]) / ntau; 
    dy[2] = (ninf - y[2]) / stau;
   