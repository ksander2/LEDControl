#ifndef PIPEMANAGER_H
#define PIPEMANAGER_H

#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "commandreceiver.h"
using namespace std;

class PipeManager
{
public:
    PipeManager(string pipeName, int size, CommandReceiver *receiver);

    bool createPipe();
    bool openPipe();
    bool listenPipe();

private:
    string _name;
    int _size;
    int fd, len;
    char *buf;

    CommandReceiver *_commandReceiver;
};

#endif // PIPEMANAGER_H
