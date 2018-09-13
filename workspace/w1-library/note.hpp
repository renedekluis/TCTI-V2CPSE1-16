#ifndef _NOTE_HPP
#define _NOTE_HPP

// ===========================================================================
//
// frequencies of standard notes
//
// ===========================================================================

class note {
public:

   // from https://www.seventhstring.com/resources/notefrequencies.html
   
	static const int P		=  0;
   
	static const int C0		=  16;
	static const int C0s	=  17;
	static const int D0		=  18;
	static const int D0s	=  19;
	static const int E0		=  20;
	static const int F0		=  21;
	static const int F0s	=  23;
	static const int G0		=  24;
	static const int G0s	=  25;
	static const int A0		=  27;
	static const int A0s	=  29;
	static const int B0 	=  30;
   
   										
	static const int C1		=  32;
	static const int C1s	=  34;
	static const int D1		=  36;
	static const int D1s	=  38;
	static const int E1		=  41;
	static const int F1		=  43;
	static const int F1s	=  46;
	static const int G1		=  49;
	static const int G1s	=  51;
	static const int A1		=  55;
	static const int A1s	=  58;
	static const int B1 	=  61;
  
  
   											
	static const int C2		=  65;
	static const int C2s	=  69;
	static const int D2		=  73;
	static const int D2s	=  77;
	static const int E2		=  82;
	static const int F2		=  87;
	static const int F2s	=  92;
	static const int G2		=  98;
	static const int G2s	=  103;
	static const int A2		=  110;
	static const int A2s	=  116;
	static const int B2 	=  123;
   
   
   											
	static const int C3		=  130;
	static const int C3s	=  138;
	static const int D3		=  146;
	static const int D3s	=  155;
	static const int E3		=  164;
	static const int F3		=  174;
	static const int F3s	=  185;
	static const int G3		=  196;
	static const int G3s	=  207;
	static const int A3		=  220;
	static const int A3s	=  233;
	static const int B3 	=  246;
   
   
   											
	static const int C4		=  261;
	static const int C4s	=  277;
	static const int D4		=  293;
	static const int D4s	=  311;
	static const int E4		=  329;
	static const int F4		=  349;
	static const int F4s	=  370;
	static const int G4		=  392;
	static const int G4s	=  415;
	static const int A4		=  440;
	static const int A4s	=  466;
	static const int B4 	=  493;
   
   
   											
	static const int C5		=  523;
	static const int C5s	=  554;
	static const int D5		=  587;
	static const int D5s	=  622;
	static const int E5		=  659;
	static const int F5		=  698;
	static const int F5s	=  740;
	static const int G5		=  784;
	static const int G5s	=  830;
	static const int A5		=  880;
	static const int A5s	=  932;
	static const int B5 	=  987;
   
	static const int C6    	=  1047;
	static const int C6s    =  1109;
	static const int D6    	=  1175;
	static const int D6s    =  1245;
	static const int E6    	=  1319;
	static const int F6    	=  1397;
	static const int F6s    =  1480;
	static const int G6    	=  1568;
	static const int G6s    =  1661;
	static const int A6    	=  1760;
	static const int A6s    =  1865;
	static const int B6 	=  1976;

	static const int C7    	=  2093;
	static const int C7s    =  2217;
	static const int D7    	=  2349;
	static const int D7s    =  2489;
	static const int E7    	=  2637;
	static const int F7    	=  2794;
	static const int F7s    =  2960;
	static const int G7    	=  3136;
	static const int G7s    =  3322;
	static const int A7    	=  3520;
	static const int A7s    =  3729;
	static const int B7 	=  3951;

	static const int C8    	=  4186;
	static const int C8s    =  4435;
	static const int D8   	=  4699;
	static const int D8s    =  4978;
	static const int E8    	=  5274;
	static const int F8    	=  5588;
	static const int F8s    =  5920;
	static const int G8    	=  6272;
	static const int G8s    =  6645;
	static const int A8    	=  7040;
	static const int A8s    =  7459;
	static const int B8 	=  7902;
   
   
   const int frequency;
    
	const int duration;
	
   static const int dF = 1'000'000;  // full measure
   static const int dH = dF / 2;     // half measure
   static const int dQ = dF / 4;     // quarter measure
   static const int dQH = dQ / 2;	// Half quarter measure
   
   
};

#endif

