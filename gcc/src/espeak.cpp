

#include <speak_lib.h>
#include <string.h>

int main(int argc, char* argv[] ) {
	
	char const* text={"Hello Muthanna"};
	
	espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 0, NULL, 0 );
	espeak_SetVoiceByName("default");

	unsigned int flags=espeakCHARS_AUTO | espeakENDPAUSE;
	
	espeak_Synth(text, (int)strlen(text), 0,POS_CHARACTER,0, flags, NULL, NULL );
			
	espeak_Synchronize();

	return 0;
}
