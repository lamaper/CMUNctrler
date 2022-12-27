#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
/*
@author lamaper
@Date 2022/5/3
@Copyright lamaper@qq.com
*/ 
using namespace std;
ofstream ofs;
string Time2Str(){
    time_t tm;
    time(&tm); //获取time_t类型的当前时间
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&tm));
    return tmp;
}
class WorkingExpection{
	public:
		WorkingExpection(string e,int i,int d):error(e),error_id(i),error_date(d){};
		int ShowError(){
			cout << endl << "程序遇到"<< error <<"错误而终止运行" << endl;
			return 1;
		}
	private:
		string error;
		int error_id;
		int error_date;
};
class Meeting{
	private:
		string committee;//委员会 
		string topic;//议题 
		string rule;//议事规则 
		int agenda = 0;//议程 
		int delegate = 0;//代表人数 
		int rudele = 1;//代表制 
		
		int symple_dele = 0;//简单多数 
		int O5_dele = 0;//20%多数 
		int T2_dele = 0;//2/3多数
		int state = 0;//状态 
	//	const string Vstate[10] = {"会议创建成功，等待点名","暂时休会","会议已结束","正在进行主发言名单","正在进行有主持核心磋商","正在进行自由磋商","正在进行投票","正在点名"}; 
	public:
		int att_dele;//出席人数 
		int MSLtime = 1200; 
		Meeting(string c = "XXXX委员会",string t = "XXXX问题",string r = "罗伯特议事规则",int d = 0,int rud = 1):committee(c),topic(t),rule(r),delegate(d),rudele(rud){
			state = 0;
			}
		void setter(string c = "XXXX委员会",string t = "XXXX问题",string r = "罗伯特议事规则",int d = 0,int rud = 1){
			committee = c;topic = t;rule = r;delegate = d;rudele = rud;
			return;
			}
		int get_T2(){
			return T2_dele;
		}
		int get_O5(){
			return O5_dele;
		}
		int get_rud(){
			return rudele;
		}
		string get_rul(){
			return rule;
		}
		string get_top(){
			return topic;
		}
		string get_com(){
			return committee;
		}
		int getatt(){
			return att_dele;
		}
		int getDelegate(){
			return delegate;
		}
		int getsyde(){
			return symple_dele;
		}
		void Edit(){
			/* TODO (#1#): 添加判断，当人数大于、小于时该怎么办 */
			cout << "===================================" << endl;
			cout << "开始修改会议信息" << endl;
			cout << "请输入委员会名称：" << endl << ">>"; 
			cin >> committee;
			cout << "请输入议题：" << endl << ">>"; 
			cin >> topic;
			cout << "请输入议事规则：" << endl<< ">>"; 
			cin >> rule;
			cout << "请输入总代表人数：" << endl<< ">>"; 
			cin >> delegate;
			cout << "请输入请输入代表制（单人/多人代表）：" << endl<< ">>"; 
			cin >> rudele;
			cout << "修改成功！！！" << endl;
		}
		void DoMath(){
			symple_dele = 0.5 * att_dele;
			cout << att_dele;
			O5_dele = 0.2 * att_dele;
			T2_dele = 2 * att_dele / 3;
		} 
		void ShowMeetingInfo(){
			DoMath();
			cout << "\n\n\n\n\n=========当前会议信息============" << endl;
			cout << "委员会：" << committee << endl;
			cout << "议题：" << topic << endl;
			cout << "议事规则："  << rule << endl;
			cout << "代表总人数：" << delegate << endl;
			cout << "*******************************" << endl;
	//		cout << "当前会议状态:" << Vstate[state] << endl;
	//		cout << "当前会期：" << agenda << endl;
			cout << "当前总出席人数：" << att_dele << endl;
			cout << "当前简单多数：" << symple_dele << endl;
			cout << "当前20%多数：" << O5_dele << endl;
			cout << "当前2/3多数：" << T2_dele << endl;
			cout << "===================================" << endl;
			cout <<"\n";
		}
};
struct Delegates{
		int ID;
		string seats;
		int states = 0;
		string Vstates[5] = {"创建成功，等待初始化","未被点名","出席","缺席"};
		
	void ShowDeleInfo(){
			cout << "===================================" << endl;
			cout << "席位：" << seats << endl;
			cout << "状态：" << states << endl;
			cout << "ID："  << ID << endl;
			cout << "===================================" << endl;
		}
};//目前没用 
struct Motions{
	string name;
	int type;//1有主持，2自由，3修改主发言名单时长，4.开始投票，5.休会
	string from;
	int time;
	int everytime;
};//目前没用 
class Controler{
	private:
		string ctrl;
	public:
		int NormalAsking(){
			cout << "\n\n\n\n\n===========操作菜单==============" << endl;			
			cout << "点名--------输入D" << endl; 
			cout << "继续主发言名单--------输入Z" << endl;
			cout << "开启动议平台--------输入K" << endl;
			cout << "显示会议信息--------输入L" << endl;
			cout << "修改会议信息--------输入E" << endl;
			cout << "退出系统--------输入exit" << endl;
			cout << "===================================" << endl;
			while(1){
				cout << ">>";
				cin >> ctrl;
				if(ctrl == "D"){
					return 1;
					
				}else if(ctrl == "Z"){
					return 2;
					
				}else if(ctrl == "K"){
					return 3;
					
				}else if(ctrl == "L"){
					return 4;
					
				}else if(ctrl == "E"){
					return 5;
					
				}else if(ctrl == "exit"){
					return 789;
					
				}else{
					cout << "非标准输入，请重新输入"<<endl;
				}
			}
		}
}; 
void SpeakingList(int t , int e){
		int times;
		int evertime;	
	string time = Time2Str();
	ofs << time.c_str() << endl;
	queue<string> Qq;
	cout << time.c_str() << endl;
	cout << "\n\n\n\n\n=========有主持名单开启===========" << endl;
	ofs << "\n\n\n\n\n=========有主持名单开启===========" << endl;
	cout << "输入b结束发言"<<endl;
	cout << "当前发言名单时长："<<evertime<<endl;
	cout << "===========================" << endl;
	while(1){
		if(Qq.empty()){
			cout << "发言名单已空，是否继续添加成员？（Y/N）"<< endl << ">>";
			string tmp;
			while(1){
				cin >> tmp;
				if(tmp == "Y"){
					break; 
				}else if(tmp == "N"){
					return;
				}else{
					cout << "非标准输入，请重新输入"<< endl << ">>";
				}
			}cout << "开始录入(结束请输入over)" << endl;
			while(1){
				cout << "\n>>";
				cin >> tmp;
				if(tmp != "over"){
					Qq.push(tmp);
				}else{
					break;
				}
			}
		}
		while(!Qq.empty()){
			string now = Qq.front();
			cout << "请" << now << "代表进行发言";
			ofs << time.c_str() << " ";
			ofs << now << "代表进行发言"<< endl;
			string arr;
			while(!Qq.empty()){
				cout << "\n>>";
				cin >> arr;
				if(arr == "b"){
					Qq.pop();
					cout <<  now << "代表发言结束"<<endl;
					break;
				}
			}
			/* TODO (#1#): 让渡 */
		}
	}
}
/* TODO (#1#): 让渡
 */
/* TODO (#1#): 计时器
 */
/* TODO (#5#): UI界面 */
Meeting m;
Delegates d[100];
Controler c;
queue<string> Q;
void GetDeleList(){
	string tmpl;
	int cnt = 0;
	string time = Time2Str();
	ofs << time.c_str() << endl;
	cout << time.c_str() << endl;
	cout << "\n\n\n\n\n=========开始录入代表============" << endl;
	cout << "输入<席位名称>"<<endl;
	cout << "===========================" << endl;
	for(int i = 1 ; i <= m.getDelegate() ; i++){
		cout << "\n开始录入第" << i << "个代表的信息"<< endl << ">>";
		cin >> tmpl;
		d[i].seats = tmpl;
		d[i].ID = i;
		d[i].states = 1;	
	}
} 
void CallName(){
	string tmpl;
	int cnt = 0;
	string time = Time2Str();
	ofs << time.c_str() << endl;
	cout << time.c_str() << endl;
	cout << "\n\n\n\n\n=========开始点名==============" << endl;
	ofs << "\n\n\n\n\n=========开始点名==============" << endl;
	cout << "出席输入1，缺席输入0"<<endl;
	cout << "=========输入over结束录入========" << endl;
	for(int i = 1 ; i <= m.getDelegate() ; i++){
		cout << d[i].seats << endl << ">>";
		cin >> tmpl;
		if(tmpl == "1"){
			ofs << d[i].seats <<"出席"<<endl;
			cnt++;
			d[i].states = 2;
		}else{
			ofs << d[i].seats <<"缺席"<<endl;
			d[i].states = 3;
		}
	}
	m.att_dele = cnt;
	m.ShowMeetingInfo();
}
void MainSpeakingList(){
	if(m.getatt() == 0){
		cout << "*****请先点名！******" <<endl;
		return;
	}
	string time = Time2Str();
	ofs << time.c_str() << endl;
	cout << "\n\n\n\n\n=========主发言名单开启===========" << endl;
	ofs << "\n\n\n\n\n=========主发言名单开启===========" << endl;
	cout << "输入k开始发言，输入b结束发言，输入out暂时退出主发言名单"<<endl;
	cout << "当前主发言名单时长："<<m.MSLtime<<endl;
	cout << "===========================" << endl;
	while(1){
		if(Q.empty()){
			cout << "发言名单已空，是否继续添加成员？（Y/N）"<< endl << ">>";
			ofs << "发言名单已空"<< endl ;
			string tmp;
			while(1){
				cin >> tmp;
				if(tmp == "Y"){
					break; 
				}else if(tmp == "N"){
					cout << "该名单关闭"<<endl;
					ofs << "该名单关闭"<<endl;
					return;
				}else{
					cout << "非标准输入，请重新输入"<< endl << ">>";
				}
			}cout << "开始录入(结束请输入over)" << endl;
			while(1){
				cout << "\n>>";
				cin >> tmp;
				if(tmp != "over"){
					Q.push(tmp);
				}else{
					break;
				}
			}
		}
		while(!Q.empty()){
			string now = Q.front();
			ofs << time.c_str() << endl;
			cout << time.c_str() << endl;		
			string arr;
			cout << now << "代表即将发言\n"<<endl;
			while(!Q.empty()){
				cout << "\n>>";
				cin >> arr;
				if(arr == "b"){
					Q.pop();
					cout <<  now << "代表发言结束\n"<<endl;
					break;
				}else if(arr == "out"){
					return;
				}else if(arr == "k"){
					cout << "请" << now << "代表进行发言\n"<<endl;
					ofs << now << "代表进行发言\n"<<endl;
				} 
			}
			/* TODO (#1#): 让渡 */
		}
	}
}
void Motion(){
	if(m.getatt() == 0){
		cout << "*****请先点名！******" <<endl;
		return;
	}
	string time = Time2Str();
	cout << "\n\n\n\n\n动议平台已经开启，请问有无动议？（Y/N）"<< endl << ">>";
	ofs << "\n\n\n\n\n" << time.c_str() << "动议平台已经开启"<< endl;
	string tmp;
	while(1){
		cin >> tmp;
		if(tmp == "Y"){
			break; 
		}else if(tmp == "N"){
			return;
		}else{
			cout << "非标准输入，请重新输入"<< endl << ">>";
		}
	}
	Motions M[100];
	queue<Motions> mm;
	int cnt = 0; 
	while(1){
		cout << "请输入动议的国家(结束输入over)"<< endl << ">>";
		cin >> tmp;
		if(tmp == "over"){
			break;
		} else{
			cnt++;
			M[cnt].from = tmp;
		}
		cout << "请输入动议内容（动议类型+议题）"<< endl << ">>";
		cin >> tmp;
		M[cnt].name = tmp;
		int r;
		cout << "请输入总时长（没有则0）"<< endl << ">>";
		cin >> r;
		M[cnt].time = r;
	    cout << "请输入单位时长（没有则0）"<< endl << ">>";	
		cin >> r;
		M[cnt].everytime = r;
		mm.push(M[cnt]); 
		ofs  << M[cnt].from << "提出 " << M[cnt].name <<"(总时长:"<<M[cnt].time<<"单位时长:"<<M[cnt].everytime<<")"<<endl; 
		cout << "----------" << endl;
		ofs  << "----------" << endl;
	} 
	int rr = 0;
	bool ON = 0;//开关 
	bool RR = 0;//开关特判 
	while(!mm.empty()){
		Motions now = mm.front();
		cout << "---------------------------"<<endl;
		cout << "现在对" << now.from << "提出的 " << now.name <<"(总时长:"<<now.time<<"单位时长:"<<now.everytime<<") 进行投票"<<endl; 
		ofs  << "现在对" << now.from << "提出的 " << now.name <<"(总时长:"<<now.time<<"单位时长:"<<now.everytime<<") 进行投票"<<endl; 
		int vote = 0;
		rr++;
		cin >> vote;
		if(vote >= m.getsyde()){
			cout << "该动议获得通过"<<endl;
			ofs  << "该动议获得通过"<<endl;
			ON = 0;
			break; 
		}else{
			cout << "该动议未获得通过"<<endl;
			ofs  <<"该动议未获得通过"<<endl;
			ON = 1;
		}
		mm.pop();
		if(mm.empty() && ON == 1){
			RR = 1;
		}
	}	
	while(RR != 1){
		cout << "---------------------------"<<endl;
		cout << "是否新建发言名单？（Y/N）"<< endl << ">>";
		cin >> tmp;
		Motions now = mm.front();
		if(tmp == "Y"){
			SpeakingList(now.time,now.everytime);
			return;
		}else if(tmp == "N"){
			return; 
		}else{
			cout << "非标准输入，请重新输入"<< endl << ">>";
		}
	}
}
bool InputMeetingInfo(){
	ifstream ifs;
	ifs.open("MeetingInfo.txt",ios::in);
	if(!ifs.is_open()){
		cout << "***找不到会议信息文件，请确认文件名是否正确或文件是否存在***"<<endl;
		return 0;
	}else{
		string c,t,r;
		int d,rud;
		ifs >> c >> t >> r >> d >> rud;
		m.setter(c,t,r,d,rud);
		return 1;
	}
}
bool InputDelegateList(){
	ifstream ifs;
	ifs.open("DelegateList.txt",ios::in);
	if(!ifs.is_open()){
		cout << "***找不到代表名单文件，请确认文件名是否正确或文件是否存在***"<<endl;
		return 0;
	}else{
		int ll = m.getDelegate();
		for(int i = 1 ; i <= ll ; i++){
			ifs >> d[i].ID >> d[i].seats;
		}
		return 1;
	}
}
void OutputMeetingInfo(){
	cout << "正在导出会议配置"<<endl;
	ofstream output;
	output.open("MeetingInfo.txt",ios::out);
	output << m.get_com() << endl << m.get_top() << endl << m.get_rul() << endl;
	output << m.getDelegate() << endl << m.get_rud() << endl;
	output.close();
}
void OutputList(){
	cout << "正在导出席位名单"<<endl;
	ofstream output;
	output.open("DelegateList.txt",ios::out);
	for(int i = 1 ; i <= m.getDelegate() ; i++){
		output << d[i].ID << " " <<d[i].seats<< endl; 
	}
	output.close();
}
int main(){
	system("mode con cols=55 lines=30");
//	ios::sync_with_stdio(0);
	string time = Time2Str();		
	ofs.open("MeetingDiary.txt",ofstream::app);
	cout << "微控模拟联合国会议记录软件 Alpha 0.1.0 bulid220503\n" << endl << "Powered by lamaper" << endl << "Copyright lamaper@qq.com\n"<<endl; 
	string check;
	cout << time.c_str() << endl;
	ofs << time.c_str() << " 成功打开会议软件！" << endl;
	cout << "载入会议信息---------输入1" << endl;
	cout << "创建新的会议---------输入2" << endl;
	cout << "退出请按Ctrl + C" << endl;
	while(1){
	cout << "\n>>";
	cin >> check;
		if(check == "1"){
			if(InputMeetingInfo() && InputDelegateList()){
				cout << "-------导入成功" << endl;
				break;
			}else{
				cout << "-------导入失败" << endl;
			}
		
		} else if(check == "2"){
			m.Edit();
			m.ShowMeetingInfo();
			GetDeleList();
			break;
		}else{
			cout << "非标准输入，请重新输入！"<<endl;
		}
	}
	
	while(1){
		cout << time.c_str() << endl;
		int acc = c.NormalAsking();//1-点名，2-主发言，3-动议，4-info 
		if(acc == 1){
			CallName();
		}else if(acc == 2){
			MainSpeakingList();
		}else if(acc == 3){
			Motion();
		}else if(acc == 4){
			m.ShowMeetingInfo();
		}else if(acc == 5){
			m.Edit();
		}else if(acc == 789){
			OutputList();
			OutputMeetingInfo();
			ofs << time.c_str() << " successfully exit" <<endl;
			ofs << "微控模拟联合国会议记录软件 Alpha 0.1.0 bulid220503" << endl << "Powered by lamaper" << endl << "Copyright lamaper@qq.com"<<endl; 
			ofs.close();
			system("pause");
			return 0;
		}
	}
	return 0;
}
