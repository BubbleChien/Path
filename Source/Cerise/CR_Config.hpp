
#ifndef CR_CONFIG_HPP
#define CR_CONFIG_HPP



#define CR_VERSION_MAJOR 1
#define CR_VERSION_MINOR 0



#define CR_DEV_BUILD 0



#define CR_AUDIO_CHANNELS 8



#define CR_SECOND_VBLANK 1



#if CR_SECOND_VBLANK

#define CR_FRAME_TIME 33
#define CR_FRAME_DELTA 0.033f
#define CR_FRAME_TEXT "30FPS"
#define CR_FRAME_SECOND 30

#else

#define CR_FRAME_TIME 16
#define CR_FRAME_DELTA 0.016f
#define CR_FRAME_TEXT "60FPS"
#define CR_FRAME_SECOND 60

#endif



#define CR_STICK_RATIO 0.00625f
#define CR_STICK_DEADZONE 0.25f



#define CR_SINEX_MUL 6.0f



#define CR_MEGABYTE 1048576.0



#endif
