// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (n == 0) {
            return 0;
        }

        else if (n >= 4) {
            return read4(buf) + read(buf + 4, n - 4);
        }

        else {
            char buf_temp[4];
            int read_count = read4(buf_temp);
            int actual_count = min(read_count, n);

            if (actual_count == 1) {
                buf[0] = buf_temp[0];
            }

            else if (actual_count == 2) {
                buf[0] = buf_temp[0];
                buf[1] = buf_temp[1];
            }

            else if (actual_count == 3) {
                buf[0] = buf_temp[0];
                buf[1] = buf_temp[1];
                buf[2] = buf_temp[2];
            }

            return actual_count;
        }
    }
};
