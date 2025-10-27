#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

int main() {
    const char *port = "/dev/ttyACM0";
    int fd = open(port, O_RDONLY | O_NOCTTY);
    if (fd < 0) { perror("open"); return 1; }

    termios tty{};
    tcgetattr(fd, &tty);
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);
    tty.c_cflag = CS8 | CLOCAL | CREAD;
    tty.c_iflag = tty.c_oflag = tty.c_lflag = 0;
    tcsetattr(fd, TCSANOW, &tty);

    char buf[64];
    while (true) {
        int n = read(fd, buf, sizeof(buf)-1);
        if (n > 0) {
            buf[n] = 0;
            std::cout << buf << std::flush;
        } else usleep(100000);
    }
}

