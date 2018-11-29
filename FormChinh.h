#include "FormTimKiem.h"
#include "FormGioThuoc.h"
#include <iostream>
#include <string>

#ifndef FORMCHINH_H
#define FORMCHINH_H

using namespace std;

class FormChinh
{
	private:
		KhachHang kh = KhachHang();
	public:

		void giaoDienDK()
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
						cout<<endl<<endl<<"\t0. Menu";
						cout<<endl<<endl<<"\t1. Nhap lai ";
						cout<<endl<<endl<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
						cin>>thaoTac;
					}while(thaoTac!="0" && thaoTac != "1");
				
					if(thaoTac== "0"){system("cls"); manKhoiDong(); return;}
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
			cout<<endl<<endl<<endl<<endl<<"\t[ Enter ] ==> Quay Lai\t";

			string stop;
			getline(cin,stop);
			system("cls");manKhoiDong(); return;
		}


		void giaoDienDN()
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
				
				cout << "Ok " << kh.xacNhanTaiKhoan();
				
				while(kh.xacNhanTaiKhoan() != 2)
				{
					string thaoTac;
					if(kh.xacNhanTaiKhoan() == 0)
					{
						do
						{
							system("cls");
							cout<<endl<<endl<<"==>\tTen tai khoan khong dung"<<endl<<endl;
							cout<<endl<<endl<<"\t0. Menu";
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
							cout<<endl<<endl<<"\t0. Menu";	
							cout<<endl<<endl<<"\t1. Nhap lai ";	
							cout<<endl<<endl<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
							cin>>thaoTac;
						}while(thaoTac!= "0" && thaoTac != "1");
					}

					if(thaoTac=="0"){system("cls"); manKhoiDong(); return;}
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
			system("cls");manKhoiDong(); return;
		}

		
		//ManHinhChinh
		void manKhoiDong()
		{
			string chonMenu;
			if(KhachHang::daDangNhap == false)
			{
				do
				{
					system("cls");
					cout<<endl<<endl;
					cout<<"\t1. Dang Ky"<<endl<<endl;
					cout<<"\t2. Dang Nhap"<<endl<<endl;
					cout<<"\t3. Tim Theo Tu Khoa"<<endl<<endl;
					cout<<"\t4. Tim Theo Loai"<<endl<<endl;
					cout<<"\t5. Thoat Chuong Trinh"<<endl<<endl;
					cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
					fflush(stdin);cin>>chonMenu;
				}while(chonMenu!="1" && chonMenu!="2" && chonMenu!="3" && chonMenu!="4" && chonMenu!="5");

				if(chonMenu == "5")
				{
					system("cls");
					return;
				}
				else if(chonMenu == "1")
				{
					system("cls");
					giaoDienDK();
				}
				else if(chonMenu == "2")
				{
					system("cls");
					giaoDienDN();
				}
				else if(chonMenu == "3")
				{
					FormTimKiem ftk = FormTimKiem();
					system("cls");
					long long chon;
					chon = ftk.giaoDienTimTheoKhoa();
					if(chon == 0) manKhoiDong();
				}
				else if(chonMenu == "4")
				{
					FormTimKiem ftk = FormTimKiem();
					system("cls");
					long long chon;
					chon = ftk.giaoDienTimTheoLoai();
					if(chon == 0) manKhoiDong();
				}
			}
			else if(KhachHang::daDangNhap == true)
			{
				
				do{
				system("cls");
				cout<<endl<<endl;
				cout<<"  Xin Chao "<<KhachHang::tenKH<<endl<<endl<<endl;
				cout<<"\t1. Dang Xuat"<<endl<<endl;
				cout<<"\t2. Quan Ly Gio Thuoc"<<endl<<endl;
				cout<<"\t3. Tim Theo Tu Khoa"<<endl<<endl;
				cout<<"\t4. Tim Theo Loai"<<endl<<endl;
				cout<<"\t5. Thoat Chuong Trinh"<<endl<<endl;
				cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
				fflush(stdin); cin>>chonMenu;
				}while(chonMenu!="1" && chonMenu!="2" && chonMenu!="3" && chonMenu!="4" && chonMenu!="5");

				if(chonMenu == "5")
				{
					system("cls");
					return;
				}
				else if(chonMenu == "1")
				{
					system("cls");
					kh.dangXuat();
					manKhoiDong();
				}
				else if(chonMenu == "3")
				{
					FormTimKiem ftk = FormTimKiem();
					system("cls");
					long long chon;
					chon = ftk.giaoDienTimTheoKhoa();
					if(chon == 0) manKhoiDong();
				}
				else if(chonMenu == "4")
				{
					FormTimKiem ftk = FormTimKiem();
					system("cls");
					long long chon;
					chon = ftk.giaoDienTimTheoLoai();
					if(chon == 0) manKhoiDong();
				}
				else if(chonMenu == "2")
				{
					FormGioThuoc fgt = FormGioThuoc();
					system("cls");
					long long chon;
					chon = fgt.giaoDienGioThuoc();
					if(chon == 0) manKhoiDong();
					
				}
			}
		}
		
};


#endif
