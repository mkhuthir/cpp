

#include <speak_lib.h>
#include <string.h>

int main(int argc, char* argv[] ) {
	
	char const* text={"Robot is running out of battery please"};
	
	espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 5000, NULL, 0 );
	espeak_SetVoiceByName("default");
	
	// espeakRATE: speaking speed in word per minute.  Values 80 to 450.
	espeak_SetParameter( espeakRATE, 150, 0);

	// espeakPITCH: base pitch, range 0-100.  50=normal
	espeak_SetParameter( espeakPITCH,50, 0);

	//espeakRANGE: pitch range, range 0-100. 0-monotone, 50=normal
	espeak_SetParameter( espeakRANGE,50, 0);

	//espeakVOLUME: volume in range 0-200 or more. 0=silence, 100=normal full volume, greater values may produce amplitude compression or distortion
	espeak_SetParameter( espeakVOLUME,200, 0);

	unsigned int flags=espeakCHARS_AUTO | espeakENDPAUSE;
	
	espeak_Synth(text, (int)strlen(text), 0,POS_CHARACTER,0, flags, NULL, NULL );
	
	espeak_Synchronize();

	return 0;
}
