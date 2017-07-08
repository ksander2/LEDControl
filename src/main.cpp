#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

#include "domain/led.h"
#include "commandreceiver.h"
#include "pipemanager.h"

#define NAMEDPIPE_NAME "/tmp/my_named_pipe"
#define BUFSIZE        50

using namespace std;

int main()
{
    led *_led = new led();
    CommandReceiver *res = new CommandReceiver(_led);

    PipeManager *pm = new PipeManager(NAMEDPIPE_NAME,BUFSIZE, res);
    pm->createPipe();
    pm->openPipe();
    pm->listenPipe();

    return 0;
}

