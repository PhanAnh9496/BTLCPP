#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#ifndef KHACHHANG_H
#define KHACHHANG_H

using namespace std;

class KhachHang
{
	private:
		string matKhau;
	public:
		static string taiKhoan;
		static string tenKH;
		static bool daDangNhap;
	


	public:
		KhachHang()
		{
			//tenKH = "";
			//taiKhoan = "";
			matKhau = "";
		}

		void setTenKH(string tenKH)
		{
			this->tenKH = tenKH;
		}
		string getTenKH()
		{
			return tenKH;
		}

		void setTaiKhoan(string taiKhoan)
		{
			this->taiKhoan = taiKhoan;
		}
		string getTaiKhoan()
		{
			return taiKhoan;
		}

		void setMatKhau(string matKhau)
		{
			this->matKhau = matKhau;
		}
		string getMatKhau()
		{
			return matKhau;
		}

	private:
		void luuVaoCSDL()
		{
			fstream f;
			f.open("TaiKhoan.txt", ios::out | ios::app);
			
			string enter = "\n";
			f<<enter<<taiKhoan<<" "<<matKhau<<enter<<tenKH;
			f.close();
			return;
		}
		void loadUpTCD()
		{
			vector<string> listTCD;
			vector<string> listTCDS;
			string enter = "\n";
			string tam;
			
			fstream f1;
			f1.open("ThuocChuaDatS.txt",ios::in);

			while(!f1.eof())
			{
				f1>>tam;
				if(tam == KhachHang::taiKhoan)
				{
					f1>>tam;
					while(tam!="ketthucTCD")
					{
						listTCD.push_back(tam);
						f1>>tam;
					}
					break;
				}				
			}

			fstream f2;
			f2.open("ThuocChuaDat.txt",ios::out);

			for(int i=0; i<listTCD.size(); i++)
			{
				f2<<enter<<listTCD.at(i);
			}
			
			f1.close();
			f2.close();
		}

		void loadUpDT()
		{
			vector<string> listDT;
			vector<string> listDTS;
			string enter = "\n";
			string tam;
			
			fstream f1;
			f1.open("DonThuocS.txt",ios::in);
			f1.ignore();
			while(!f1.eof())
			{
				getline(f1,tam);
				if(tam == KhachHang::taiKhoan)
				{
					getline(f1,tam);
					while(tam!="ketthucDT")
					{
						listDT.push_back(tam);
						getline(f1,tam);
					}
					break;
				}
				
			}

			fstream f2;
			f2.open("DonThuoc.txt",ios::out);

			for(int i=0; i<listDT.size(); i++)
			{
				f2<<enter<<listDT.at(i);
			}
			
			f1.close();
			f2.close();
		}


	public:
		bool kiemTraTrungLap()
		{
			fstream f;
			f.open("TaiKhoan.txt", ios::in);
			string s1,s2,s3;
			while(!f.eof())
			{
				f>>s1>>s2;f.ignore();
				getline(f,s3);
				if(taiKhoan == s1)
				{
					f.close();
					return true;
				} 
					
			}
			f.close();
			return false;
		}
		
		void taoTaiKhoan()
		{
			luuVaoCSDL();
		}


		long long xacNhanTaiKhoan()
		{	
			fstream f;
			f.open("TaiKhoan.txt", ios::in);
			string s1,s2,s3;
			while(!f.eof())
			{
				f>>s1>>s2;f.ignore();
				getline(f,s3);
				if(taiKhoan == s1)
				{
					if(matKhau != s2)
					{
						f.close();
						return 1;
					}
					else if(matKhau == s2)
					{
						tenKH = s3;
						f.close();
						return 2;
					}
				} 
					
			}
			f.close();
			return 0;
		}

		void dangNhap()
		{
			daDangNhap = true;
			loadUpTCD();
			loadUpDT();
		}

		void dangXuat()
		{
			daDangNhap = false;
		}
		
};

#endif

