#include <conio.h>//ʹ�ÿ⺯��getch() 
#include <cstdio>//��stdio.h��������c++ͷ�ļ�����ʽ���ֳ���
#include <iostream>
   using namespace std;
   int k=0,jiu=0,x=0,g=0,qian=1000,z=0;
void tushuguan(); 
void shangdian();
void gangkou();
void xiaofangju();
void lvguan();
void jiaotang();
void map();
void huangguan();
void fanhui();
void guangchang(); 
void shangdian0();
void shangdian1();
   char  a[15][130] = { 
                   "|                  ӡ˹é˹С���ͼ                     |", 
                   "|  o�㳡  0���λ��  $�̵� @�ۿ� &������ #�ù� *�������|",
				   "|                                                       |",
				   "|      |-----|------------|    &--------|               |",
				   "|            |            |             |               |",
				   "|            |            |             |               |",
				   "|------|-----|            |             |       |----@  |",
				   "|      o     |            |-------------|-------|       |",
				   "|            |                          |               |",
				   "|            |                          |-----------|   |",
				   "|            |-----------------*              |         |",
				   "|            |                                |-----#   |",
				   "|            |--------------$                           |",
				   "|                                                       |" };
	char b[11][100] = {
	           "|   + Ŧ���ﲨ��ͼ���  = Ŧ���ﲨ�ػ�վ    |",
	           "|                                             |",
	           "|-------------|-------------=                 |",
	           "|             |                               |",
	           "|             +                               |",
			   };

	int main(){	
	int n = 0, l = 1,x=0,y=0;
	int i = 0,g=0;
	for (i = 0; i <= 5; i++)
	cout << b[i] << endl;
   		char ch;
   		while(1){ 
		b[4][14]='+',b[2][28]='=';
   	    ch = _getch();
    	if (ch == 'w'){
	   	if (b[x - 1][y] == '-' || b[x - 1][y] == '|' || b[x - 1][y] == '+' || b[x - 1][y] == '=' ){
	   	        	if (b[x - 1][y] == '='){
					system("cls");
						if(g>0)
		        	{
					map();
					system("cls");}
					else
					fanhui();}
					if (b[x - 1][y] == '+'){
					system("cls");
					tushuguan();
					g++;
					system("cls");}
		 if (b[x + 1][y] != ' ' || b[x - 1][y] != ' '){
					b[x][y] = '|';}
				else{
					b[x][y] = '-';}
						x--;
				b[x][y] = '0';
				system("cls");
				i = 0;
				for (i = 0; i <= 5; i++)
				cout << b[i] << endl;
		 } 
   } 
   	if (ch == 's'){
	   	if (b[x + 1][y] == '-' || b[x + 1][y] == '|' || b[x + 1][y] == '+' || b[x + 1][y] == '=' ){
	   	        	if (b[x + 1][y] == '='){
					system("cls");
			    		if(g>0)
		        	{
					map();
					system("cls");}
					else
					fanhui();}
					if (b[x + 1][y] == '+'){
					system("cls");
					tushuguan();
					g++;
					system("cls");}
		 if (b[x + 1][y] != ' ' || b[x - 1][y] != ' '){
					b[x][y] = '|';}
				else{
					b[x][y] = '-';}
						x++;
				b[x][y] = '0';
				system("cls");
				i = 0;
				for (i = 0; i <= 5; i++)
					cout << b[i] << endl;
		 } 
   } 
   	if (ch == 'a'){
	   	if (b[x][y - 1] == '-' || b[x][y - 1] == '|' || b[x][y - 1] == '+' || b[x][y - 1] == '=' ){
	   	        	if (b[x][y - 1] == '='){
					system("cls");
				   	if(g>0)
		        	{
					map();
					system("cls");}
					else
					fanhui();}
					if (b[x][y - 1] == '+'){
					system("cls");
					tushuguan();
					g++;
					system("cls");}
		 if (b[x + 1][y] != ' ' || b[x - 1][y] != ' '){
					b[x][y] = '|';}
				else{
					b[x][y] = '-';}
						y--;
				b[x][y] = '0';
				system("cls");
				i = 0;
				for (i = 0; i <= 5; i++)
					cout << b[i] << endl;
		 } 
   } 
   if (ch == 'd'){
	   	if (b[x][y + 1] == '-' || b[x][y + 1] == '|' || b[x][y + 1] == '+' || b[x][y + 1] == '=' ){
	   	        	if (b[x][y + 1] == '='){
					system("cls");
		        	if(g>0)
		        	{
					map();
					system("cls");}
					else
					fanhui();}
					system("cls");}
					if (b[x][y + 1] == '+'){
					system("cls");
					tushuguan();
					g++;
					system("cls");}
		 if (b[x + 1][y] != ' ' || b[x - 1][y] != ' '){
					b[x][y] = '|';}
				else{
					b[x][y] = '-';}
						y++;
				b[x][y] = '0';
				system("cls");
				i = 0;
				for (i = 0; i <= 5; i++)
					cout << b[i] << endl;
		 } 
   } 
}
	
	
void map(){
		cout<<"����������ȥ��ӡ˹é˹�İ�ʿ�ϣ��Ǹ��ʹڲ�����״�Ĺֵ������������Ժ����֮��ȥ"<<endl;
		cout <<"�����ʿ��˾������һ����ν�ġ�ӡ˹é˹������ɫ�������ޱ��飬�����Ͼɵİ�ʿ����ǰ��"<< endl;
   	    cout <<"��ɳ����ɯ�ݹ��ɵ�½�ط羰Ҳ�𽥱�û�����һ·�Ͽ�����һ�����ᡣ���������ľ�ţ�����ڱ���ˮ��ʴ����½֮�ϡ�Ŀ֮"<< endl;
     	cout <<"����������һƬ��ɪ������������Сʱ�ĵ�����һ������������֮�µ����������ҵ���ǰ��ӡ˹é˹����վ��"<< endl;
     	cout<<"�ķϵ����ݣ��ƾɵ����ᣬ�����·��ؼ���һ��"<<endl;
    	cout <<"�Ĵ����ߵ��飬��������"<< endl;
    	cout <<"�����������..."<< endl;
    	getch();
    	system("cls");
    	
	int n = 0, l = 1,x=0,y=0;
	int i = 0;
	for (i = 0; i <= 14; i++)
	cout << a[i] << endl;
   		char ch;
   		while(1){
   		a[12][28]='$',a[7][7]='o',a[10][31]='*',a[6][53]='@',a[3][31]='&',a[11][52]='#';
   	    ch = _getch();
    	if (ch == 'w'){
	   	if (a[x - 1][y] == '-' || a[x - 1][y] == '|' || a[x - 1][y] == '$' || a[x - 1][y] == '@' || a[x - 1][y] == '&' || a[x - 1][y] == '#' || a[x - 1][y] == '*'|| a[x - 1][y] == 'o' ){
	   	        	if (a[x - 1][y] == '$'){
					if(k=0)
					shangdian0();
					system("cls");
					if(k=1)
					shangdian1();
					system("cls");}
					if (a[x - 1][y] == '@'){
					system("cls");
					gangkou();
					system("cls");}
					if (a[x - 1][y] == '&'){
						system("cls");
					    xiaofangju();
						system("cls"); }
					if (a[x - 1][y] == '#'){
					system("cls");
					lvguan();
					system("cls");}
					if (a[x - 1][y] == '*'){
					system("cls");
					jiaotang();
					system("cls");}
					if (a[x - 1][y] == 'o'){
					system("cls");
					guangchang();
					system("cls");}
		 if (a[x + 1][y] != ' ' || a[x - 1][y] != ' '){
					a[x][y] = '|';}
				else{
					a[x][y] = '-';}
						x--;
				a[x][y] = '0';
				system("cls");
				i = 0;
				for (i = 0; i <= 14; i++)
					cout << a[i] << endl;
		 } 
   } 
   	if (ch == 's'){
	   	if (a[x +1][y] == '-' || a[x + 1][y] == '|' || a[x + 1][y] == '$' || a[x + 1][y] == '@' || a[x + 1][y] == '&' || a[x + 1][y] == '#' || a[x + 1][y] == '*' || a[x + 1][y] == 'o'){
	   	        	if (a[x + 1][y] == '$'){
						if(k=0)
					shangdian0();
					system("cls");
					if(k=1)
					shangdian1();
					system("cls");}
					if (a[x + 1][y] == '@'){
					system("cls");
					gangkou();
					system("cls");}
					if (a[x + 1][y] == '&'){
						system("cls");
					    xiaofangju();
						system("cls");}
					if (a[x + 1][y] == '#'){
					system("cls");
					lvguan();
					system("cls");}
					if (a[x + 1][y] == '*'){
					system("cls");
					jiaotang();
					system("cls");}
					if (a[x + 1][y] == 'o'){
					system("cls");
					guangchang();
					system("cls");}
		 if (a[x + 1][y] != ' ' || a[x - 1][y] != ' '){
					a[x][y] = '|';}
				else{
					a[x][y] = '-';}
						x++;
				a[x][y] = '0';
				system("cls");
				i = 0;
				for (i = 0; i <= 14; i++)
					cout << a[i] << endl;
		 } 
   } 
   	if (ch == 'a'){
	   	if (a[x][y - 1] == '-' || a[x][y - 1] == '|' || a[x][y - 1] == '$' || a[x][y - 1] == '@' || a[x][y - 1] == '&' || a[x][y - 1] == '#' || a[x][y - 1] == '*' || a[x][y - 1] == 'o'){
	   	        	if (a[x][y - 1] == '$'){
						if(k=0)
					shangdian0();
					system("cls");
					if(k=1)
					shangdian1();
					system("cls");}
					if (a[x][y - 1] == '@'){
					system("cls");
					gangkou();
					system("cls");}
					if (a[x][y - 1] == '&'){
							system("cls");
					    xiaofangju();
						system("cls"); }
					if (a[x][y - 1] == '#'){
					system("cls");
					lvguan();
					system("cls");}
					if (a[x][y - 1] == '*'){
					system("cls");
					jiaotang();
					system("cls");}
					if (a[x][y - 1] == 'o'){
					system("cls");
					guangchang();
					system("cls");}
		 if (a[x + 1][y] != ' ' || a[x - 1][y] != ' '){
					a[x][y] = '|';}
				else{
					a[x][y] = '-';}
						y--;
				a[x][y] = '0';
				system("cls");
				i = 0;
				for (i = 0; i <= 14; i++)
					cout << a[i] << endl;
		 } 
   } 
   	if (ch == 'd'){
	   	if (a[x][y + 1] == '-' || a[x][y + 1] == '|' || a[x][y + 1] == '$' || a[x][y + 1] == '@' || a[x][y + 1] == '&' || a[x][y + 1] == '#' || a[x][y + 1] == '*' || a[x][y + 1] == 'o'){
	   	        	if (a[x][y + 1] == '$'){
					if(k=0)
					shangdian0();
					system("cls");
					if(k=1)
					shangdian1();
					system("cls");
					}
					if (a[x][y + 1] == '@'){
					system("cls");
					gangkou();
					system("cls");}
					if (a[x][y + 1] == '&'){
						system("cls");
					    xiaofangju();
						system("cls");} 
					if (a[x][y + 1] == '#'){
					system("cls");
					lvguan();
					system("cls");}
					if (a[x][y + 1] == '*'){
					system("cls");
					jiaotang();
					system("cls");}
					if (a[x][y + 1] == 'o'){
					system("cls");
					guangchang();
					system("cls");}
		 if (a[x + 1][y] != ' ' || a[x - 1][y] != ' '){
					a[x][y] = '|';}
				else{
					a[x][y] = '-';}
						y++;
				a[x][y] = '0';
				system("cls");
				i = 0;
				for (i = 0; i <= 14; i++)
					cout << a[i] << endl;
		 } 
   } 
}
}
void shangdian0(){
		cout<<"�����˼�ϡ�٣�����ĳ��ԭ�����������̵��̽��Ϣ���Ͼ��ڳ�����˵�İ�ʿ�뿪֮ǰ�һ��д�ѵ�ʱ��"<<endl; 
		cout<<"������˵ء��Ӵ��ҵ���һλС���ӣ��Һܾ�������Ȼû����һ��ӡ˹é˹��"<<endl; 
		cout <<"�����������..."<< endl;
		getch();
		k++;	
}
void shangdian1(){
int b,l;
	    cout<<"1.���ϰ彻̸"<<endl; 
	    cout<<"2.������Ʒ"<<endl; 
	    cout<<"3.���ص�ͼ"<<endl; 
	    cin>>l;
	    system("cls");
	    if(l=1){
	    	cout<<"�Ҵ������е�֪��Ҳ���Ȳ����ѴӰ���ķ���������﹤���ģ�����һ������Ҳʮ�����ӡ˹é˹�ġ��������顱"<<endl;
	    	cout<<"ͬʱ�������������ص㣬������������Ľ�����������ӵ����˿����˽⵽�κι���ӡ˹é˹�Ĺ�ȥ��Ψһ"<<endl;
	    	cout<<"Ը�⿪�ڵĵ����ˣ���һ��������ˡ����׵��Ͼƹ��������������ָ�������"<<endl;
	    	cout <<"�����������..."<< endl;
    		getch();
	    	x++;
	    	system("cls");
		}
		if(l=2){
			cout<<"�������Ϊ"<< qian << endl;
			cout<<"����1�����"<<endl;
			cout<<"����2��������"<<endl;
			cin>>b; 
			system("cls");
			if(b=1){
				cout<<"����ɹ�"<<endl;
				qian=qian-200;
				cout<<"�������Ϊ"<< qian << endl;
				cout <<"�����������..."<< endl;
    			getch();
   				system("cls");
				jiu++; 
			}
			else{
				cout<<"����ɹ�"<<endl;
				qian=qian-100;
				cout<<"�������Ϊ"<< qian << endl;
				cout <<"�����������..."<< endl;
    			getch();
   				system("cls");
			}
		}
} 
void tushuguan()
{
	cout<<"ֻ��Ϊ�������ӡ˹é˹����־"<<endl;
	cout<<"��鵽����Щ���ϼ�����ûʲô��"<<endl;
	cout<<"ֻ��1846��ӡ˹é˹�����ߺ�һ��������Ŧ���ﲨ�صĻʹ����������ע��"<<endl;
	cout <<"�����������..."<< endl;
   	getch();
	system("cls");
	huangguan();
	cout <<"�����������..."<< endl;
   	getch();
   	cout<<"�ʹ��������Ű�����˵������Լ���·������ˮ��ͼ��"<<endl; 
	system("cls");	
	cout <<"�����������..."<< endl;
   	getch();
	return;
	
	
}
void gangkou(){
	cout<<"19���ͳ�ӡ˹é˹�������һλ����--�±��£���������һ������"<<endl;
	cout<<"���Ϲ�ʯ��ᾣ�ÿ��ʯͷ��������������Ŀ����������"<<endl;
	cout<<"��ʹ�ڽ��ĺ����Լ�û�����ˣ���Щ��������ץ����"<<endl;
	cout<<"����Ĵ���������ԭ��"<<endl;
	cout<<"ÿ��һ��ʱ�䣬��Щ�����ͻὫ����ĺ����׼������װ�����˵�����"<<endl;
	cout<<"�������������ˣ���Щ����������ʼ����������"<<endl;
	cout<<"��������������չʾ��һ�������õ�Ǧ�����󣬾�˵���Դ��κεط��ٻ�Ը��ǰ��������"<<endl;
	cout<<"���������Լ��������״��������л�������Ʊ�"<<endl;
	cout<<"�ܿ�佨����ӡ˹é˹�뵺��ó�׺���"<<endl;
	cout<<"����һ��±���ͻȻ���ֵ��ϵ�����ȫ����ʧ�ˣ��²���Щ������ܱ������ߵ�ӡ��(��������Ψһ���µĶ���)�ɵ���"<<endl;
	cout<<"��������������ʶһλ�������񣬿��Ա�������󸻴��"<<endl;
	cout <<"�����������..."<< endl;
   	getch();
	system("cls");
	cout <<"�����������..."<< endl;
   	getch();
	system("cls");
	cout<<"ӡ˹é˹�ʹ˻���������������ʼ����������"<<endl;
	cout<<"��Щ�ַ����������Ҫô���ż���Ҫô���Լ��뿪��"<<endl;
	cout<<"���հ±��º�����ͬ�ﱻ��������"<<endl; 
	cout<<"ͻȻ��һ����Щ���˴Ӻ��������˳���"<<endl;
	cout<<"�±��±����˳�����ǹ�����޺��������ڶ�" <<endl;
	cout<<"�����ӡ˹é˹������"<<endl;
	system("cls");	
	cout<<"ͻȻ���Ͼƹ����Զ��һƬ�����У�"<<endl; 
	cout<<"��Щ�������������ˣ����ܣ�����"<<endl;
	cout<<"���������ĳ���߽���ֻ��������������뷨"<<endl; 
	getch();
	system("cls");
	 
} 
void xiaofangju(){
		cout<<"�������ţ���������ӡ˹é˹�����֣�һλ������ͷñ��������������ǰ������һ���޾����"<<endl;
		if(jiu>0){
			cout<<"�ڿ��������еľ�ƿ�Ժ�������˫�۷Ź⣬������Զ���˹�����������"<<endl;
			cout<<"����ǰ���ۿ���̸"<<endl;
			cout <<"�����������..."<< endl;
    		getch();
			system("cls");
			x++;
			g++; 
			return; }
		else{
		cout<<"ȥ���"<<endl;
			getch();
			system("cls");
		return;}
		} 
void lvguan(){
	cout<<"��Ȼ�㱻�ոյ��������Ÿ��𾪵��ˣ������㻹�Ǵ�����סһ����"<< endl;
	cout<<"����1��ס"<<endl; 
	cin>>z;
	if(z=1)
	{
		cout<<"��Ϸ����"<<endl;
	cout <<"�����������..."<< endl;
   	getch();
	system("cls");
	}
	else 
	{ 
	cout<<"��Ϸ����"<<endl;
	cout <<"�����������..."<< endl;
   	getch();
   	system("cls");
   	} 
} 
void jiaotang(){
	cout<<"���������������Ψһ���ã�ֻ��һ��ͷ���ιڵĺ�����ʦ��������ػ�ͷ������һ�ۣ����ģ�"<<endl;
	cout<<"�����ιڼ�ֱ�����ڳ��й��п����Ľ��һģһ�������������������Ĺ��죬�ǻ��������ģ����"<<endl;
	cout<<"������ԶԶ������"<<endl;
	cout <<"�����������..."<< endl;
    getch();
}
void fanhui() 
{
				cout<<"�㻹û��̽���꣬����̽��"<<endl;
				cout <<"�����������..."<< endl;
    			getch();
   				system("cls");
				return;
}
 void huangguan()
 {
 cout<<"	                                ................                               "<<endl;
 cout<<"                               . .......,]].....                                   "<<endl;
 cout<<"                               ........=eeee...                                    "<<endl;
 cout<<"                               .........lee`...                                    "<<endl;
 cout<<"                             ..........,eeel...........                            "<<endl;
 cout<<"                           . ........./eeeeee`.........                            "<<endl;
 cout<<"                  .        ......=eeleeeeeeeeeleeO......        ......             "<<endl;
 cout<<"             .....         ......=ee/eeeeeeeee/ee/.....            .  .            "<<endl;
 cout<<"       .......,.*....................,eeeeeee^.....................,......         "<<endl;
 cout<<"       ......*eeeel]].................=eeeeee..................]leeee^....         "<<endl;
 cout<<"      ........leeOeeeeel`..............eeeee`............../eeeeeOeee`... .        "<<endl;
 cout<<"      .............leeeeee...]ee]......=eeee......,/el...=eeeeee........           "<<endl;
cout<<".....................eeeee^...eeeel`....=eeee.....]eeee^...eeeee^..................."<<endl;
cout<<".....................=eeee^........lee`.eeeee^./ee`........eeeee...................."<<endl;
cout<<"..,/eel`.............,Oeeee`........,eeeeeOeeeee^........./eeee^............../eee]."<<endl;
cout<<".=eeeeee^......,]/Oeee^leeeel........,eeee.=eeel`.......,eeeee^leee]]`.......Oeeeee^"<<endl;
cout<<"..eeeeeeeeeeeeeeeeeee^..=eeeeeeel/eeeeeeee./eeeeeeee/OeeeeeeO...eeeeeeeeeeeeeeeeeee^"<<endl;
cout<<"....[[*,leeeeeeeeeeee^....,eeeeeeeeeeeOeeeleeeeeeeeeeeeeee/.....eeeeeeeeeeeee`.,[`.."<<endl;
cout<<"..........leeeeeeeeee^.........[[`....=eeeeeeee....[[[..........eeeeeeeeeee`........"<<endl;
cout<<"............leeeeeeeee`..............,eeeeeeeeel.............../eeeeeeeee`.........."<<endl;
cout<<".  ..  .......[eeeeeeeel.......`..../eeeee^eeeeee`...........,eeeeeeee/............."<<endl;
cout<<"        ........,eeeeeeeee]]....]/eeeeeee/.,eeeeeeee]]...,]/eeeeeeee/......         "<<endl;
cout<<"        . ........,eeeeeeeeeeeeeeeeeeeee`....leeeeeeeeeeeeeeeeeeee/......           "<<endl;
cout<<"          ...........,eeeeeeeeeeeeeeeO`.,eee`..leeeeeeeeeeeeeee/`........           "<<endl;
cout<<"          .......eel`....,[lOO/[[[`.`.]eeeeeeel....[[[OO[[[[....,eeO....            "<<endl;
cout<<"            .....=eeeeel]].....,]]/eeeeeeeeeeeeeeeO]`.....,]]eeeeee^....            "<<endl;
cout<<"            ......eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee.....            "<<endl;
cout<<"            ......leeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee/.....            "<<endl;
cout<<"              .........................................................             "<<endl;
cout<<"               .        .......................  .......                            "<<endl;
cout<<"                                ................                                    "<<endl;
 }
 void guangchang(){
 	cout<<"����������㳡�ϣ�һ�۱㿴����������Ϥ�Ļ�ɫ��ʿ�����ǣ�˾��ʦ��ȴ���������ĳ��ӻ���"<<endl;
 	cout<<"��˵�ǰ���ķ�ˣ����½���������Ҳȥ�����ˣ������Ľ����£��������˼������ù�"<<endl;
 	cout<<"���Ʋ����ù�"<<endl;
 	cout <<"�����������..."<< endl;
    getch();
   	system("cls");
 }
