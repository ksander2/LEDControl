#include "pipemanager.h"
#include <sstream>

PipeManager::PipeManager(string pipeName, int size, CommandReceiver *receiver)
{
    _name = pipeName;
    _size = size;
    _commandReceiver = receiver;

    buf = new char[size];
}

bool PipeManager::createPipe()
{

    remove(_name.c_str());
    if ( mkfifo(_name.c_str(), 0777) ) {
        perror("mkfifo");
        return 1;
    }

    return 0;

}

bool PipeManager::openPipe()
{
    if ( (fd = open(_name.c_str(), O_RDONLY )) <= 0 ) {
        perror("open");
        return 1;
    }
    cout << _name << " is opened" << endl;
    return 0;
}

bool PipeManager::listenPipe()
{
    do {
        memset(buf, '\0', _size);
        if ( (len = read(fd, buf, _size-1)) > 0 )
        {
            stringstream stream(buf);
            string word;
            stream >> word;

            string name = "/tmp/pipeno."+word;
            int fd1 = open(name.c_str(), O_WRONLY);

            if (_commandReceiver->makeCommand(buf))
            {
                const char *str = _commandReceiver->executeCommand().c_str();
                write(fd1, str, strlen(str));
                usleep(10000);
                const char *str1 ="quit\n";
                write(fd1, str1, strlen(str1));
                close(fd1);
                //unlink(name.c_str());
            }
            else
            {
                const char *str = "FAILED\n";
                write(fd1, str, strlen(str));
            }
            usleep(100000);
        }


    } while ( true );

}
