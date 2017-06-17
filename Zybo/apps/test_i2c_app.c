/*
 * simple test app for i2c driver in zybo
 * 
 */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define		I2C_DEV_FILENAME	"/dev/i2c-0"
#define		BUFSIZE				32
#define		EMPTY				0

int main(int argc, char** argv) {
	int i2cFd, rSize, sum, rc = 0;
	char buf[BUFSIZE] = {EMPTY};
	i2cFd = open(I2C_DEV_FILENAME, O_RDWR);
	if(i2cFd > 0) {
		rSize = read(i2cFd, buf, BUFSIZE);
		buf[rSize - 1] = EMPTY;
		while(BUFSIZE - rc > 0) {
			printf("%d ", buf[rc]);
			rc ++;
		}
		printf("\nfile size : %d\n", rSize);
	}else printf("%s open error", I2C_DEV_FILENAME);
	close(i2cFd);
	return 0;
}