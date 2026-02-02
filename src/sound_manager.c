/****************************************************************************
 *
 * Copyright 2024 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//***************************************************************************
// Included Files
//***************************************************************************

#include <tinyara/config.h>
#include <string.h>
#include <debug.h>
#include <fcntl.h>
#include <sys/wait.h>

int play_music( int argc, char *argv[] )
{
	const char *name = "soundplayer";
	const char *path = "/res/kernel/audio/test.mp3";
	const char *volume = "3";
	const char *sample_rate = "48000";
	const char *stream_policy = "1";
	const char *looping = "1";
	char *player_argv[] = {
		(char *)name,
		(char *)path,
		(char *)volume,
		(char *)sample_rate,
		(char *)stream_policy,
		(char *)looping,
		NULL
	};

	int player_argc = 6;
	soundplayer_main( player_argc, player_argv );
	return 0;
}

int task_play_sound( int argc, char *argv[] )
{
	/*
	Probably the most stupid way to play sound but it is the only
	way to ensure that MediaPlayer is completely destroyed after
	playback. Some memory leak in mediaplayer framework is suspected...
	*/
	while ( 1 )
	{
		pid_t pid = task_create( "play_music", SCHED_PRIORITY_DEFAULT, 16384, play_music, NULL );
		waitpid( pid, NULL, 0 );
		sleep( 5 );
	}
	return 0;
}
