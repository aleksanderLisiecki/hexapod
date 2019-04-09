#include "maestro.h"
//strona pololu z opisem maestro po angielsku      https://www.pololu.com/docs/0J40/all#5
maestro::maestro()
{
    UARTInit();
}
maestro::~maestro()
{
    close(fd);
}
int maestro::maestroGetError()//pobiera blad
{
    unsigned char command[] = { 0xAA, 0xC, 0x21 };
	if (write(fd, command, sizeof(command)) != 3)
	{
		mvprintw(10, 10, "Blad wpisywania maestro");
		refresh();
		return -1;
	}

	int n = 0;
	unsigned char response[2];
	do
	{
		int ec = read(fd, response + n, 1);
		if (ec < 0)
		{
			mvprintw(10, 10, "Blad czytania maestro");
			refresh();
			return ec;
		}
		if (ec == 0)
		{
			continue;
		}
		n++;

	} while (n < 2);

	return (int)sqrt(response[0] + 256 * response[1]);
}
int maestro::maestroGetPosition(unsigned char channel)//pobiera pozycje kanalu
{
	unsigned char command[] = { 0xAA, 0xC, 0x10, channel };
	if (write(fd, command, sizeof(command)) == -1)
	{
		mvprintw(10, 10, "Blad wpisywania maestro do kanalu %d", channel);
		refresh();
		return -1;
	}

	int n = 0;
	char response[2];
	do
	{
		int ec = read(fd, response + n, 1);
		if (ec < 0)
		{
			mvprintw(10, 10, "Blad czytania maestro z kanalu %d	", channel);
			refresh();
			return ec;
		}
		if (ec == 0)
		{
			continue;
		}
		n++;

	} while (n < 2);

	return response[0] + 256 * response[1];
}
void maestro::maestroSetSingleTarget(unsigned char channel, unsigned short target)//podaje katy dla 1 serwa
{
	target = SetAngle(target);
	unsigned char command[] = { 0xAA, 0xC, 0x04, channel, target & 0x7F, target >> 7 & 0x7F };//0xAA, device number, 0x04, channel number, target low bits, target high bits
	if (write(fd, command, sizeof(command)) == -1)
	{
		mvprintw(10, 10, "Blad wpisywania maestro do kanalu %d	", channel);
		refresh();
	}
}
void maestro::maestroSet18Targets(vector<unsigned short> targets)//podaje katy dla 18 serw
{
    for(int i = 0;i < 18;i++)
    {
        targets[i] = SetAngle(targets[i]);
    }
    //0xAA, device number, 0x1F, number of targets, first channel number, first target low bits, first target high bits, second target low bits, second target high bits, …
	unsigned char command[] = { 0xAA, 0xC, 0x1F, 0x15,	3, 
														 targets[10] & 0x7F, targets[10] >> 7 & 0x7F ,
														 targets[17] & 0x7F, targets[17] >> 7 & 0x7F ,
														 targets[16] & 0x7F, targets[16] >> 7 & 0x7F ,
														 targets[15] & 0x7F, targets[15] >> 7 & 0x7F ,
														 targets[14] & 0x7F, targets[14] >> 7 & 0x7F ,
														 targets[13] & 0x7F, targets[13] >> 7 & 0x7F,
														 targets[12] & 0x7F, targets[12] >> 7 & 0x7F,
														 targets[11] & 0x7F, targets[11] >> 7 & 0x7F,
														 targets[0] & 0x7F, targets[0] >> 7 & 0x7F,//nieuzywany kanal 11
														 targets[0] & 0x7F, targets[0] >> 7 & 0x7F,//nieuzywany kanal 12
														 targets[0] & 0x7F, targets[0] >> 7 & 0x7F,//nieuzywany kanal 13
														 targets[9] & 0x7F, targets[9] >> 7 & 0x7F ,
														 targets[8] & 0x7F, targets[8] >> 7 & 0x7F,
														 targets[7] & 0x7F, targets[7] >> 7 & 0x7F,
														 targets[6] & 0x7F, targets[6] >> 7 & 0x7F,
														 targets[5] & 0x7F, targets[5] >> 7 & 0x7F,
														 targets[4] & 0x7F, targets[4] >> 7 & 0x7F,
														 targets[3] & 0x7F, targets[3] >> 7 & 0x7F,
														 targets[2] & 0x7F, targets[2] >> 7 & 0x7F,
														 targets[1] & 0x7F, targets[1] >> 7 & 0x7F,
														 targets[0] & 0x7F, targets[0] >> 7 & 0x7F};
	if (write(fd, command, sizeof(command)) == -1)//wysylanie
	{
		mvprintw(10, 10, "Blad wpisywania maestro");
		refresh();
		//return -1;
	}
}
void maestro::UARTInit()//inicjalizacja portu komunikacyjnego z maestro
{
	const char * device = "/dev/ttyAMA0";
	fd = open(device, O_RDWR | O_NOCTTY);
	struct termios options;
	tcgetattr(fd, &options);
	cfsetispeed(&options, B115200);
	cfsetospeed(&options, B115200);

	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;

	// no flow control
	options.c_cflag &= ~CRTSCTS;

	options.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines
	options.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl

	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
	options.c_oflag &= ~OPOST; // make raw

	options.c_cc[VMIN] = 0;
	options.c_cc[VTIME] = 20;
	
	printw("\nUARTInit()");
	//usleep(3000 * 1000);

	//return 0;
}
int maestro::SetAngle(double angle)
{
	if (angle > 180 || angle < 0)
		return 6000;
	else
	{
		angle = angle / 180.0;
		angle = angle * 1800.0 + 600.0;
		angle = angle * 4;
		return (int)angle;
	}
}
