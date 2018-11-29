
#include "KhachHang.h"

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <vector>

#ifndef THUOC_H
#define THUOC_H

using namespace std;

class Thuoc 
{
	private:
		string maThuoc;
		string tenThuoc;
		string loaiThuoc;
		long long giaTien;
		string trangThai;
		long long soLuong;

		long long demLuuMa;
		string luuMa[1000];
	public:
		Thuoc()
		{
			maThuoc = "";
			tenThuoc = "";
			loaiThuoc = "";
			giaTien = 0;
			demLuuMa = 0;
			trangThai = "ngoaigio";
		}
		
		void setMaThuoc(string maThuoc)
		{
			this->maThuoc = maThuoc;
		}
		string getMaThuoc()
		{
			return maThuoc;
		}
		
		void setTenThuoc(string tenThuoc)
		{
			this->tenThuoc = tenThuoc;
		}
		string getTenThuoc()
		{
			return tenThuoc;
		}
		
		void setLoaiThuoc(string loaiThuoc)
		{
			this->loaiThuoc = loaiThuoc;
		}
		string getLoaiThuoc()
		{
			return loaiThuoc;
		}
		
		void setGiaTien(long long giaTien)
		{
			this->giaTien = giaTien;
		}
		long long getGiaTien()
		{
			return giaTien;
		}
		
		
		void setTrangThai(string trangThai)
		{
			this->trangThai = trangThai;
		}
		string getTrangThai()
		{
			return trangThai;
		}
		
		void setSoLuong(long long soLuong)
		{
			this->soLuong = soLuong;
		}
		long long getSoLuong()
		{
			return soLuong;
		}
		
		long long getDemLuuMa()
		{
			return demLuuMa;
		}
		
		void showThuoc()
		{
			cout<<"  ";
			cout<<setw(8)<< left << maThuoc;
			cout<<setw(35)<< left << tenThuoc;
			cout<<setw(20)<< left << loaiThuoc;
			cout<<setw(15)<< left <<giaTien;
			cout<<endl;
		}
		
	
	private:
		
		string chuanHoa(string s)
		{
			for(long long i=0; i<s.size(); i++)
			{
				if(s[i] >= 97 && s[i] <=122) s[i]-=32;
			}
			
			string out = "";
			
			for(long long i=0; i<s.size(); i++)
			{	
				string tam = "";
				if(s[i] != ' ')
				{
					while(s[i]!=' ' && s[i]!='\0')
					{
						tam.push_back(s[i]);
						i++;
					}
					out += tam; out.push_back(' ');
				}	
			}

			out.erase(out.size()-1);

			return out;
		}
		
		void loadDownTCD()
		{
			vector<string> listTCD;
			vector<string> listTCDS;
			string enter = "\n";
			string tam;
			fstream f1;
			f1.open("ThuocChuaDat.txt",ios::in);

			while(!f1.eof())
			{
				f1>>tam;
				listTCD.push_back(tam);
			}

			fstream f2;
			f2.open("ThuocChuaDatS.txt",ios::in);

			while(!f2.eof())
			{
				f2>>tam;
				if(tam == KhachHang::taiKhoan){
					while(tam != "ketthucTCD")
					{
						f2>>tam;
					}
				}
				else listTCDS.push_back(tam);
			}

			fstream f3;
			f3.open("ThuocChuaDatS.txt",ios::out);
			f3<<enter<<KhachHang::taiKhoan;
			for(int i=0; i<listTCD.size(); i++)
			{
				f3<<enter<<listTCD.at(i);
			}
			f3<<enter<<"ketthucTCD";
			for(int i=0; i<listTCDS.size(); i++)
			{
				f3<<enter<<listTCDS.at(i);
			}
			f1.close();
			f2.close();
			f3.close();
		}
		
		
	public:
		
		bool checkMa(string mT)
		{
			for(long long i=0; i<demLuuMa; i++)
			{
				if(luuMa[i] == mT) return true;
			}
			return false;
		}
		
		void timTheoKhoa(string khoa)
		{
			demLuuMa = 0;
			khoa = chuanHoa(khoa);
			fstream f;
			f.open("Thuoc.txt",ios::in);

			string mT, tTh, lT;
			long long gT;
			cout<<endl<<endl<<endl;
			cout<<"  ";
			cout<<setw(8)<< left << "Ma Thuoc";
			cout<<setw(35)<< left << "Ten Thuoc";
			cout<<setw(20)<< left << "Loai";
			cout<<setw(15)<< left << "Gia Tien";
			cout<<"________________________________________________________________________________";
			cout<<endl<<endl;

			while(!f.eof())
			{
				f>>mT; f.ignore(); 
				getline(f,tTh);
				getline(f,lT);
				f>>gT; f.ignore();
				if(tTh.find(khoa) != -1 || lT.find(khoa) != -1)
				{
					luuMa[demLuuMa] = mT; demLuuMa++;
					maThuoc = mT;
					tenThuoc = tTh;
					loaiThuoc = lT;
					giaTien = gT;
					showThuoc();
					
				}
			}
			
			cout<<"________________________________________________________________________________"<<endl;
			cout<<"  Co "<<demLuuMa<<" Ket Qua"<<endl;
			cout<<"________________________________________________________________________________";

			if(demLuuMa == 0)
			{
				system("cls");
				cout<<endl<<endl<<"==>\tKhong Tim Thay Ket Qua";
			} 

			f.close();
		}
		
		void timTheoLoai(string loai)
		{
			demLuuMa = 0;
			fstream f;
			f.open("Thuoc.txt",ios::in);

			string mT, tTh, lT;
			long long gT;
			
			cout<<endl<<endl;
			cout<<"  ";
			cout<<setw(8)<< left << "Ma Thuoc";
			cout<<setw(35)<< left << "Ten Thuoc";
			cout<<setw(20)<< left << "Loai";
			cout<<setw(15)<< left << "Gia Tien";
			cout<<"________________________________________________________________________________";
			cout<<endl<<endl;

			if(loai == "ALL")
			{
				while(!f.eof())
				{
					f>>mT; f.ignore(); 
					getline(f,tTh);
					getline(f,lT);
					f>>gT; f.ignore();
					
						luuMa[demLuuMa] = mT; demLuuMa++;
						maThuoc = mT;
						tenThuoc = tTh;
						loaiThuoc = lT;
						giaTien = gT;
						showThuoc();

				}
				cout<<"________________________________________________________________________________"<<endl;
				cout<<"  Co "<<demLuuMa<<" Ket Qua"<<endl;
				cout<<"________________________________________________________________________________";
			}
			else
			{
				while(!f.eof())
				{
					f>>mT; f.ignore(); 
					getline(f,tTh);
					getline(f,lT);
					f>>gT; f.ignore();
					if(lT == loai)
					{
						luuMa[demLuuMa] = mT; demLuuMa++;
						maThuoc = mT;
						tenThuoc = tTh;
						loaiThuoc = lT;
						giaTien = gT;
						showThuoc();
					}
				}
				cout<<"________________________________________________________________________________"<<endl;
				cout<<"  Co "<<demLuuMa<<" Ket Qua"<<endl;
				cout<<"________________________________________________________________________________";
			}

			f.close();
		}
		
		
		void showChiTiet(string mT)
		{
			string ma, tam;
			fstream f;
			f.open("ChiTiet.txt",ios::in);
			cout<<endl<<"    Thong Tin Chi Tiet Thuoc"<<endl<<endl;
			cout<<"________________________________________________________________________________";
			while(!f.eof())
			{
				getline(f,ma);
				if(ma == mT)
				{
					getline(f,tam);
					cout<<endl<<"    "<<setw(30)<< left << "Ten Thuoc :";
					cout<<setw(45)<< left <<tam;

					getline(f,tam);
					cout<<endl<<endl<<"    "<<setw(30)<< left << "Gia Tien :";
					cout<<setw(45)<< left <<tam;

					getline(f,tam);
					cout<<endl<<endl<<"    "<<setw(30)<< left << "Hang San Xuat :";
					cout<<setw(45)<< left <<tam;

					getline(f,tam);
					cout<<endl<<endl<<"    "<<setw(30)<< left << "Loai Thuoc:";
					cout<<setw(45)<< left <<tam;

					getline(f,tam);
					cout<<endl<<endl<<"    "<<setw(30)<< left << "Ngay San Xuat :";
					cout<<setw(45)<< left <<tam;

					getline(f,tam);
					cout<<endl<<endl<<"    "<<setw(30)<< left << "Han Su Dung :";
					cout<<setw(45)<< left <<tam;

					getline(f,tam);
					cout<<endl<<endl<<"    "<<setw(30)<< left << "Hinh Dang:";
					cout<<setw(45)<< left <<tam;

					// for(long long i=0; i<3; i++)
					// {
					// 	getline(f,tam);
					// 	cout<<tam<<endl<<endl;
					// }
					cout<<endl<<endl<<"________________________________________________________________________________";
					return;
				}
				else
				{
					for(long long i=0; i<7; i++)
					{
						getline(f,tam);
					}
				}	
			}

		}
		
		
		void choVaoGio(string mT)
		{
			string enter = "\n";

			fstream f;
			f.open("ThuocChuaDat.txt", ios::out | ios::app );
			f<<enter<<mT;
			f.close();
			loadDownTCD();
		}
		
		
		vector<Thuoc> getThuocTrongGio()
		{
			vector<Thuoc> listTH;
			Thuoc t = Thuoc();
			string ma;
			
			fstream f;
			f.open("ThuocChuaDat.txt",ios::in);


			cout<<endl<<endl;
			cout<<"  ";
			cout<<setw(8)<< left << "Ma Thuoc";
			cout<<setw(35)<< left << "Ten Thuoc";
			cout<<setw(20)<< left << "Loai";
			cout<<setw(15)<< left << "Gia Tien";
			cout<<"________________________________________________________________________________";
			cout<<endl<<endl;

			while(!f.eof())
			{							
				f.ignore();
				f>>ma;
				
			fstream f1;
			f1.open("Thuoc.txt",ios::in);

			string mT, tTh, lT;
			long long gT;
			
				while(!f1.eof())
				{
					
					f1>>mT; f1.ignore(); 
					getline(f1,tTh);
					getline(f1,lT);
					f1>>gT; f1.ignore();
					if(mT == ma)
					{
						t.setMaThuoc(mT);
						t.setTenThuoc(tTh);
						t.setLoaiThuoc(lT);
						t.setGiaTien(gT);
						t.showThuoc();
						listTH.push_back(t);
					}
					
				}
				f1.close();
			}
					
			cout<<"________________________________________________________________________________"<<endl;
			cout<<"  Co "<<listTH.size()<<" Ket Qua"<<endl;
			cout<<"________________________________________________________________________________";
				

			f.close();
			return listTH;
		}
		
		
		void xoaThuocTrongGio(string ma)
		{
			string tam, enter = "\n";
			
			if(ma=="all")
			{
				fstream f1;
				f1.open("ThuocChuaDat.txt",ios::out);
				f1<<enter;
				f1.close();
				loadDownTCD();
				return;
			}

			vector<string> listma;
			fstream f;
			f.open("ThuocChuaDat.txt",ios::in);
			while(!f.eof())
			{
				f.ignore();
				f>>tam;
				if(tam != ma) listma.push_back(tam);
			}
			f.close();

			fstream f1;
			f1.open("ThuocChuaDat.txt",ios::out);
			for(int i=0; i<listma.size(); i++)
			{
				f1<<enter<<listma.at(i);
			}
			f1.close();
			loadDownTCD();
		}
		
};

#endif






















