#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int min, sec, video_t, pos_t, op_start_t, op_end_t;
    char colon;
    stringstream ss = stringstream(video_len);
    ss >> min >> colon >> sec;
    video_t = min * 100 + sec;

    ss = stringstream(pos);
    ss >> min >> colon >> sec;
    pos_t = min * 100 + sec;

    ss = stringstream(op_start);
    ss >> min >> colon >> sec;
    op_start_t = min * 100 + sec;

    ss = stringstream(op_end);
    ss >> min >> colon >> sec;
    op_end_t = min * 100 + sec;

    for (string cmd: commands) {
        if (pos_t >= op_start_t && pos_t <= op_end_t) {
            pos_t = op_end_t;
        }
        if (cmd == "next") {
            pos_t += 10;
            if (pos_t % 100 >= 60) {
                pos_t += 40;
            }
            if (pos_t > video_t) {
                pos_t = video_t;
            }
        }
        else if (cmd == "prev") {
                if (pos_t % 100 < 10) {
                    if (pos_t / 100 > 0) {
                        pos_t -= 100;
                        pos_t += 50;
                    }
                    else {
                        pos_t = 0;
                    }
                }
                else {
                    pos_t -= 10;
                }
        }

    }
    if (pos_t >= op_start_t && pos_t <= op_end_t) {
            pos_t = op_end_t;
    }
    string answer = "";
    for (int i = 1000; i > 0; i /= 10) {
        int temp = pos_t / i;
        pos_t %= i;
        answer.append(to_string(temp));
        if (i == 100) {
            answer.append(":");
        }
    }
    return answer;
}