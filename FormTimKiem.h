#include "FormMuaThuoc.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

#ifndef FORMTIMKIEM_H
#define FORMTIMKIEM_H


using namespace std;

class FormTimKiem 
{
	private:
		Thuoc t = Thuoc();
		KhachHang kh = KhachHang();
		FormMuaThuoc muaThuoc = FormMuaThuoc();
		
		
	public:
		void giaoDienDKPhu()
		{
			string tenTK, tenKH, mK;

			cout<<endl;
			cout<<"  DANG KY"<<endl<<endl;
			cout<<"\tNhap Tai Khoan:\t";
				cin>>tenTK; 
				kh.setTaiKhoan(tenTK);
				while(kh.kiemTraTrungLap())
				{
					string thaoTac;
					do
					{
						system("cls");
						cout<<endl<<endl<<"==>\tTen tai khoan da su dung"<<endl<<endl;
						cout<<endl<<endl<<"\t0. << Back <<";
						cout<<endl<<endl<<"\t1. Nhap lai ";
						cout<<endl<<endl<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
						cin>>thaoTac;
					}while(thaoTac!="0" && thaoTac != "1");
				
					if(thaoTac== "0"){return;}
					else
					{
							system("cls");
							cout<<endl;
							cout<<"  DANG KY"<<endl<<endl;
							cout<<"\tNhap Tai Khoan:\t";
							cin>>tenTK;
							kh.setTaiKhoan(tenTK);
					}
				}				

			cout<<endl<<"\tNhap Mat Khau:\t";
				cin>>mK;
				kh.setMatKhau(mK);

			cout<<endl<<"\tNhap Ho Va Ten:\t";
				cin.ignore(); getline(cin,tenKH);
				kh.setTenKH(tenKH);

			kh.taoTaiKhoan();
			cout<<endl<<"==>\tDANG KY THANH CONG !\t";
			long long z;
			cout<<endl<<endl<<"\t0. << Back << ";
			cout<<endl<<endl<<"\t1. Dang Nhap ";
			cout<<endl<<endl<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
			cin>>z;
			if(z==1){system("cls"); giaoDienDNPhu(); return;}
			else {return;}
			return;
		}
		
		
		void giaoDienDNPhu()
		{
			string tenTK, mK;

			cout<<endl;
			cout<<"  DANG NHAP"<<endl<<endl;
			cout<<"\tNhap Tai Khoan:\t";
				cin>>tenTK; 
				kh.setTaiKhoan(tenTK);
			
			cout<<endl<<endl;
			cout<<"\tNhap Mat Khau:\t";
				cin>>mK; 
				kh.setMatKhau(mK);
				
				while(kh.xacNhanTaiKhoan() != 2)
				{
					string thaoTac;
					if(kh.xacNhanTaiKhoan() == 0)
					{
						do
						{
							system("cls");
							cout<<endl<<endl<<"==>\tTen tai khoan khong dung"<<endl<<endl;
							cout<<endl<<endl<<"\t0. << Back <<";
							cout<<endl<<endl<<"\t1. Nhap lai ";
							cout<<endl<<endl<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
							cin>>thaoTac;
						}while(thaoTac!= "0" && thaoTac != "1");
					}
					else if(kh.xacNhanTaiKhoan() == 1)
					{
						do
						{
							system("cls");
							cout<<endl<<endl<<"==>\tMat khau khong dung"<<endl<<endl;
							cout<<endl<<endl<<"\t0. << Back <<";	
							cout<<endl<<endl<<"\t1. Nhap lai ";	
							cout<<endl<<endl<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
							cin>>thaoTac;
						}while(thaoTac!= "0" && thaoTac != "1");
					}

					if(thaoTac=="0"){return;}
					else
					{
						system("cls");
						cout<<endl;
						cout<<"  DANG NHAP"<<endl<<endl;
						cout<<"\tNhap Tai Khoan:\t";
							cin>>tenTK; 
							kh.setTaiKhoan(tenTK);
							
						cout<<endl<<endl;
						cout<<"\tNhap Mat Khau:\t";
							cin>>mK; 
							kh.setMatKhau(mK);
					}
				}

			kh.dangNhap();
			system("cls");
			cout<<endl<<endl;
			if(KhachHang::daDangNhap) cout<<"==>\t"<<kh.getTenKH()<<" DANG NHAP THANH CONG !\t";
			cout<<endl<<endl<<endl<<endl<<"\t[ Enter ] ==> Quay Lai\t";
			string stop;
			fflush(stdin);getline(cin,stop);
			return;
		}
		
		
		long long giaoDienTimTheoKhoa()
		{
			string tuKhoa;
			cout<<endl;
			cout<<"  TIM KIEM"<<endl<<endl;
			cout<<"\tNhap Tu Khoa Tim Kiem:\t";
				//cin.ignore();
				fflush(stdin);
				getline(cin,tuKhoa); 
			
			do
			{
				system("cls");
				cout<<endl<<endl<<" Ket qua cho tu khoa: "<<tuKhoa;
				t.timTheoKhoa(tuKhoa);
				if(t.getDemLuuMa() != 0)
				{
					string x,y;
					
					cout<<endl<<endl<<"\t0. << Menu <<"<<endl;
					cout<<endl<<endl<<"\t1. << Back <<"<<endl;
					do
					{
						cout<<endl<<endl<<" [ Nhap MaSP ] ==> [ Enter ] ";
						cin>>x;
					}while(!t.checkMa(x) && x!="0" && x!="1");
					if(x=="0"){system("cls"); return 0;}
					if(x=="1"){system("cls"); giaoDienTimTheoKhoa(); return 0;}
					cout<<endl<<endl<<"\t0. << Menu <<";
					cout<<endl<<endl<<"\t1. Xem chi tiet ";
					cout<<endl<<endl<<"\t2. Cho vao gio thuoc ";
					cout<<endl<<endl<<"\t3. Mua thuoc";
					cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
					cin>>y;
					if(y=="0"){system("cls"); return 0;}
					else if(y=="1")
					{
						system("cls");
						t.showChiTiet(x);
						string z;
						cout<<endl<<endl<<"\t0. << Menu <<";
						cout<<endl<<endl<<"\t1. << Back <<";
						cout<<endl<<endl<<"\t2. Cho vao gio thuoc ";
						cout<<endl<<endl<<"\t3. Mua thuoc";
						cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
						cin>>z;
						if(z=="0"){system("cls"); return 0;}
						else if(z=="2")
						{
							if(KhachHang::daDangNhap == false) 
							{
								system("cls");
								string z;
								cout<<endl<<endl<<"==>\tBan chua dang nhap. Dang nhap de thuc hien chuc nang ";
								cout<<endl<<endl<<"\t0. << Back <<";
								cout<<endl<<endl<<"\t1. Dang Ky ";
								cout<<endl<<endl<<"\t2. Dang Nhap ";
								cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
								cin>>z;
								if(z=="2") { system("cls"); giaoDienDNPhu();}
								else if(z=="1") { system("cls"); giaoDienDKPhu();}
							}
							else
							{
								t.choVaoGio(x);
							}
						}
						else if(z=="3")
						{
							//goi giao dien mua hang
							if(KhachHang::daDangNhap == false) 
							{
								system("cls");
								long long z;
								cout<<endl<<endl<<"==>\tBan chua dang nhap. Dang nhap de thuc hien chuc nang ";
								cout<<endl<<endl<<"\t0. << Back <<";
								cout<<endl<<endl<<"\t1. Dang Ky ";
								cout<<endl<<endl<<"\t2. Dang Nhap ";
								cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
								cin>>z;
								if(z==2) { system("cls"); giaoDienDNPhu();}
								else if(z==1) { system("cls"); giaoDienDKPhu();}
							}
							else
							{
								vector<Thuoc> listThuoc;
								listThuoc.push_back(t);
								muaThuoc.giaoDienMuaThuoc(listThuoc);
							}
						}
					}
					else if(y=="2")
					{
						if(KhachHang::daDangNhap == false) 
						{
							system("cls");
							long long z;
							cout<<endl<<endl<<"==>\tBan chua dang nhap. Dang nhap de thuc hien chuc nang ";
							cout<<endl<<endl<<"\t0. << Back <<";
							cout<<endl<<endl<<"\t1. Dang Ky ";
							cout<<endl<<endl<<"\t2. Dang Nhap ";
							cout<<endl<<endl<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
							cin>>z;
							if(z==2) { system("cls"); giaoDienDNPhu();}
							else if(z==1) { system("cls"); giaoDienDKPhu();}
						}
						else
						{
							t.choVaoGio(x);
						}
					}
					else if(y=="3")
					{
						//goi giao dien mua hang
						if(KhachHang::daDangNhap == false) 
						{
							system("cls");
							long long z;
							cout<<endl<<endl<<"==>\tBan chua dang nhap. Dang nhap de thuc hien chuc nang ";
							cout<<endl<<endl<<"\t0. << Back <<";
							cout<<endl<<endl<<"\t1. Dang Ky ";
							cout<<endl<<endl<<"\t2. Dang Nhap ";
							cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
							cin>>z;
							if(z==2) { system("cls"); giaoDienDNPhu();}
							else if(z==1) { system("cls"); giaoDienDKPhu();}
						}
						else
						{
							vector<Thuoc> listThuoc;
							listThuoc.push_back(t);
							muaThuoc.giaoDienMuaThuoc(listThuoc);
						}
					}

				}
				else 
				{

					string stop;
					cout<<endl<<endl<<endl<<endl<<"\t[ Enter ] ==> Quay Lai\t";
					fflush(stdin);getline(cin,stop);fflush(stdin);
					system("cls"); return 0;
				}
				
				system("cls");
			}while(true);

		}	
		
		
		long long giaoDienTimTheoLoai()
		{
			string loai;
			do
			{
				system("cls");
				cout<<endl;
				cout<<"  TIM KIEM"<<endl<<endl;
				cout<<"\t1. ALL\t"<<endl<<endl;
				cout<<"\t2. Khang Sinh\t"<<endl<<endl;
				cout<<"\t3. Thuoc Cam Cum\t"<<endl<<endl;
				cout<<"\t4. Thuoc Ho\t"<<endl<<endl;
				cout<<"\t5. Men Vi Sinh\t"<<endl<<endl;
				cout<<"\t6. Vitamin\t"<<endl<<endl;
				cout<<"\t7. Thuoc Dau Bung\t"<<endl<<endl;
				cout<<"\t8. Thuoc Chong Say\t"<<endl<<endl;
				cout<<endl<<"\t0. << Menu << \t"<<endl<<endl<<endl;
				cout<<" [ Nhap So ] ==> [ Enter ]  ";
				cin>>loai;
			}while(loai < "0" || loai > "8");

			do
			{
				if(loai == "0"){system("cls"); return 0;}
				else if(loai == "1"){system("cls"); t.timTheoLoai("ALL"); }
				else if(loai == "2"){system("cls"); t.timTheoLoai("Khang Sinh");}
				else if(loai == "3"){system("cls"); t.timTheoLoai("Thuoc Cam Cum");}
				else if(loai == "4"){system("cls"); t.timTheoLoai("Thuoc Ho");}
				else if(loai == "5"){system("cls"); t.timTheoLoai("Men Vi Sinh");}
				else if(loai == "6"){system("cls"); t.timTheoLoai("Vitamin");}
				else if(loai == "7"){system("cls"); t.timTheoLoai("Thuoc Dau Bung");}
				else if(loai == "8"){system("cls"); t.timTheoLoai("Thuoc Chong Say");}
				
				string x,y;
				cout<<endl<<endl<<"\t0. << Menu <<"<<endl;
				cout<<endl<<endl<<"\t1. << Back <<"<<endl;
				do
				{
					cout<<endl<<endl<<" [ Nhap MaSP ] ==> [ Enter ] ";
					cin>>x;
				}while(!t.checkMa(x) && x!="0" && x!="1");
				if(x=="0"){system("cls"); return 0;}
				if(x=="1"){system("cls"); giaoDienTimTheoLoai(); return 0;}
				cout<<endl<<endl<<"\t0. << Menu <<";
				cout<<endl<<endl<<"\t1. Xem chi tiet ";
				cout<<endl<<endl<<"\t2. Cho vao gio thuoc ";
				cout<<endl<<endl<<"\t3. Mua thuoc";
				cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
				cin>>y;
				if(y=="0"){system("cls"); return 0;}
				else if(y=="1")
				{
					system("cls");
					t.showChiTiet(x);
					string z;
					cout<<endl<<endl<<"\t0. << Menu <<";
					cout<<endl<<endl<<"\t1. << Back <<";
					cout<<endl<<endl<<"\t2. Cho vao gio thuoc ";
					cout<<endl<<endl<<"\t3. Mua thuoc";
					cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
					cin>>z;
					if(z=="0"){system("cls"); return 0;}
					else if(z=="2")
					{
						if(KhachHang::daDangNhap == false) 
						{
							system("cls");
							string z;
							cout<<endl<<endl<<"==>\tBan chua dang nhap. Dang nhap de thuc hien chuc nang ";
							cout<<endl<<endl<<"\t0. << Back <<";
							cout<<endl<<endl<<"\t1. Dang Ky ";
							cout<<endl<<endl<<"\t2. Dang Nhap ";
							cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
							cin>>z;
							if(z=="2") { system("cls"); giaoDienDNPhu();}
							else if(z=="1") { system("cls"); giaoDienDKPhu();}
						}
						else
						{
							t.choVaoGio(x);
						}
					}
					else if(z=="3")
					{
						//muaHang.giaoDienMuaHang();
						if(KhachHang::daDangNhap == false) 
						{
							system("cls");
							long long z;
							cout<<endl<<endl<<"==>\tBan chua dang nhap. Dang nhap de thuc hien chuc nang ";
							cout<<endl<<endl<<"\t0. << Back <<";
							cout<<endl<<endl<<"\t1. Dang Ky ";
							cout<<endl<<endl<<"\t2. Dang Nhap ";
							cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
							cin>>z;
							if(z==2) { system("cls"); giaoDienDNPhu();}
							else if(z==1) { system("cls"); giaoDienDKPhu();}
						}
						else
						{
							vector<Thuoc> listThuoc;
							listThuoc.push_back(t);
							muaThuoc.giaoDienMuaThuoc(listThuoc);
						}
					}
				}
				else if(y=="2")
				{
					if(KhachHang::daDangNhap == false) 
					{
						system("cls");
						long long z;
						cout<<endl<<endl<<"==>\tBan chua dang nhap. Dang nhap de thuc hien chuc nang ";
						cout<<endl<<endl<<"\t0. << Back <<";
						cout<<endl<<endl<<"\t1. Dang Ky ";
						cout<<endl<<endl<<"\t2. Dang Nhap ";
						cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
						cin>>z;
						if(z==2) { system("cls"); giaoDienDNPhu();}
						else if(z==1) { system("cls"); giaoDienDKPhu();}
					}
					else
					{
						t.choVaoGio(x);
					}
				}
				else if(y=="3")
				{
					if(KhachHang::daDangNhap == false) 
					{
						system("cls");
						long long z;
						cout<<endl<<endl<<"==>\tBan chua dang nhap. Dang nhap de thuc hien chuc nang ";
						cout<<endl<<endl<<"\t0. << Back <<";
						cout<<endl<<endl<<"\t1. Dang Ky ";
						cout<<endl<<endl<<"\t2. Dang Nhap ";
						cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
						cin>>z;
						if(z==2) { system("cls"); giaoDienDNPhu();}
						else if(z==1) { system("cls"); giaoDienDKPhu();}
					}
					else
					{
						vector<Thuoc> listThuoc;
						listThuoc.push_back(t);
						muaThuoc.giaoDienMuaThuoc(listThuoc);
					}
				}

				system("cls");
			}while(true);


			return 1;
		}	
		
};

#endif
