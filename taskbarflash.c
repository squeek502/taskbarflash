#define WINVER 0x501
#define _WIN32_WINNT 0x501
#include <windows.h>
#include <stdio.h>
#include <string.h>

#define INFINITE_FLASHES 0
#define DEFAULT_BLINK_RATE 0

static void usage(FILE *const stream, const char *program)
{
	fprintf(stream, "Usage: %s [options] [num_flashes [flash_rate_ms]]\n \
\n\
  Options:\n\
    -h, --help          Print this help screen\n\
    -t, --tray          Flash the taskbar icon (default)\n\
    -w, --window        Flash the window caption\n\
    -c, --caption       Alias for --window\n\
    --all               Flash both the taskbar icon and the window caption\n", program);
}

int main(int argc, const char* argv[])
{
	DWORD flags = 0;
	UINT numFlashes = INFINITE_FLASHES;
	DWORD flashRate = DEFAULT_BLINK_RATE;

	int argStart = 1;
	while (argc > argStart && argv[argStart][0] == '-')
	{
		const char *flagsArg = argv[argStart];
		if (_stricmp("--help", flagsArg) == 0 ||
			_stricmp("-h", flagsArg) == 0 ||
			_stricmp("--usage", flagsArg) == 0 ||
			_stricmp("-?", flagsArg) == 0)
		{
			usage(stdout, argv[0]);
			return EXIT_SUCCESS;
		}
		else if (_stricmp("--tray", flagsArg) == 0 ||
			_stricmp("-t", flagsArg) == 0)
		{
			flags |= FLASHW_TRAY;
		}
		else if (_stricmp("--window", flagsArg) == 0 || 
			_stricmp("-w", flagsArg) == 0 ||
			_stricmp("--caption", flagsArg) == 0 ||
			_stricmp("-c", flagsArg) == 0)
		{
			flags |= FLASHW_CAPTION;
		}
		else if (_stricmp("--all", flagsArg) == 0 || 
			_stricmp("-wt", flagsArg) == 0 || 
			_stricmp("-tw", flagsArg) == 0 ||
			_stricmp("-tc", flagsArg) == 0 ||
			_stricmp("-ct", flagsArg) == 0)
		{
			flags |= FLASHW_ALL;
		}
		else
		{
			fprintf(stderr, "Unknown option: %s\n\n", flagsArg);
			usage(stderr, argv[0]);
			return EXIT_FAILURE;
		}
		argStart++;
	}

	// if no flags, then use the default
	if (argStart == 1) flags = FLASHW_TRAY;

	for (int i = argStart; i < argStart+2 && i < argc; i++)
	{
		int arg = atoi(argv[i]);
		if (i == argStart) numFlashes = arg;
		else flashRate = arg;
	}

	HWND window = GetConsoleWindow();
	if (!window) return EXIT_FAILURE;
	FLASHWINFO info = { sizeof(info), window, FLASHW_TIMERNOFG | flags, numFlashes, flashRate };
	FlashWindowEx(&info);
}
