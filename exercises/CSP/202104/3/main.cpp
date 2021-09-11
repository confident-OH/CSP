#include <iostream>

using namespace std;
const int IPNUM = 10001;
long long int IPtime[10010];
char IPflag[10010];
string IPname[10010];
long long N, Tdef, Tmax, Tmin;
long long TimeNow;
string H;
string Hall = string("*");
string LOFR = string("OFR");
string LACK = string("ACK");
string LNAK = string("NAK");

void changeTime(long long time)
{
    for(int i = 1; i<=N;i++){
        if(IPflag[i] == 1 && IPtime[i] <= TimeNow){
            IPflag[i] = 0;
            IPname[i].clear();
            IPtime[i] = 0;
        }
        if(IPflag[i] == 2 && IPtime[i] <= TimeNow){
            IPflag[i] = 3;
        }
    }
}

long long int DIS_IP_Found(string &name, long long time)
{
    for(int i = 1; i<=N; i++){
        if(IPname[i] == name){
            IPflag[i] = 1;
            IPtime[i] = time;
            return i;
        }
    }
    for(int i = 1; i<=N; i++){
        if(IPflag[i] == 0){
            IPflag[i] = 1;
            IPname[i] = name;
            IPtime[i] = time;
            return i;
        }
    }
    for(int i = 1; i<=N; i++){
        if(IPflag[i] == 3){
            IPflag[i] = 1;
            IPname[i] = name;
            IPtime[i] = time;
            return i;
        }
    }
    return 0;
}

bool ACKORNAK(string &name, long long IP, long long time)
{
    if(IP>N){
        return false;
    }
    if(IPname[IP] == name){
        IPflag[IP] = 2;
        IPtime[IP] = time;
        return true;
    }
    return false;
}

long long TurnTime(long long time)
{
    long long timegap = time - TimeNow;
    if(time == 0){
        return Tdef + TimeNow;
    }
    if(timegap < Tmin){
        return Tmin + TimeNow;
    }
    if(timegap > Tmax){
        return Tmax + TimeNow;
    }
    return time;
}

void ZhuanWeiK(string &name)
{
    for(int i = 1; i<=N;i++){
        if(IPname[i] == name){
            IPname[i].clear();
            IPflag[i] = 0;
            IPtime[i] = 0;
        }
        break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    string Hsend;
    string Hrev;
    string Info;
    long long int IPitem, Timeover, IPsendback, Timesendback;
    cin >> N >> Tdef >> Tmax >> Tmin >> H;
    cin >> n;
    for(int i = 0; i<n; i++){
        // 每个报文进行处理
        cin >> TimeNow;
        cin >> Hsend >> Hrev >> Info >> IPitem >> Timeover;
        changeTime(TimeNow);
        if(Hrev == H || Hrev == Hall){
            if(Hrev == H && Info == string("REQ")){
                // 正式分配IP dizhi
                Timesendback = TurnTime(Timeover);
                if(ACKORNAK(Hsend, IPitem, Timesendback)){
                    // ACK
                    cout <<  H << " " << Hsend << " " << "ACK " << IPitem << " " << Timesendback << endl;
                }
                else{
                    // NAK
                    cout <<  H << " " << Hsend << " " << "NAK " << IPitem << " 0" << endl;
                }
            }
            if(Hrev == Hall && Info == string("DIS")){
                // 预计分配IP地址
                Timesendback = TurnTime(Timeover);
                IPsendback = DIS_IP_Found(Hsend, Timesendback);
                if(IPsendback != 0){
                    cout << H << " " << Hsend << " " << "OFR " << IPsendback << " " << Timesendback << endl;
                }
            }
        }
        else{
            if(Info == string("REQ")){
                // 将IP转为空闲
                ZhuanWeiK(Hsend);
            }
        }
    }
    return 0;
}
