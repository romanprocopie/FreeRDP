/**
 * FreeRDP: A Remote Desktop Protocol client.
 * Arguments Parsing
 *
 * Copyright 2009-2011 Jay Sorg
 * Copyright 2011 Vic Lee
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include <freerdp/settings.h>
#include <freerdp/utils/print.h>
#include <freerdp/utils/memory.h>
#include <freerdp/utils/args.h>
#include <freerdp/utils/passphrase.h>


void freerdp_parse_hostname(rdpSettings* settings, char* hostname) {
	char* p;
	if (hostname[0] == '[' && (p = strchr(hostname, ']'))
			&& (p[1] == 0 || (p[1] == ':' && !strchr(p + 2, ':')))) {
			/* Either "[...]" or "[...]:..." with at most one : after the brackets */
		settings->hostname = xstrdup(hostname + 1);
		if ((p = strchr((char*)settings->hostname, ']'))) {
			*p = 0;
			if (p[1] == ':')
				settings->port = atoi(p + 2);
		}
	} else {
		/* Port number is cut off and used if exactly one : in the string */
		settings->hostname = xstrdup(hostname);
		if ((p = strchr((char*)settings->hostname, ':')) && !strchr(p + 1, ':')) {
			*p = 0;
			settings->port = atoi(p + 1);
		}
	}
}



/**
 * Parse command-line arguments and update rdpSettings members accordingly.
 * @param settings pointer to rdpSettings struct to be updated.
 * @param argc number of arguments available.
 * @param argv string array of the arguments.
 * @param plugin_callback function to be called when a plugin needs to be loaded.
 * @param plugin_user_data pointer to be passed to the plugin_callback function.
 * @param ui_callback function to be called when a UI-specific argument is being processed.
 * @param ui_user_data pointer to be passed to the ui_callback function.
 * @return number of arguments that were parsed, or FREERDP_ARGS_PARSE_RESULT on failure or --version/--help
 */
int freerdp_parse_args(rdpSettings* settings, int argc, char** argv,
	ProcessPluginArgs plugin_callback, void* plugin_user_data,
	ProcessUIArgs ui_callback, void* ui_user_data)
{
	return 0;
}
