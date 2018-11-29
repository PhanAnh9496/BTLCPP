#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <cstring>
#include <ctime>

#include "Thuoc.h"

#ifndef DONTHUOC_H
#define DONTHUOC_H

using namespace std;

class DonThuoc 
{
	private:
		string maDT;
		KhachHang kh;
		vector<Thuoc> listThuoc;
		string ngayMua;
		string noiNhan;
		long long tongTien;
		string trangThai;
		
	public:
		void setMaDT(string maDT)
		{
			this->maDT = maDT;
		}
		string getMaDT()
		{
			return maDT;
		}
		
		void setKH(KhachHang kh)
		{
			this->kh = kh;
		}
		KhachHang getKH()
		{
			return kh;
		}
		
		void setListThuoc(vector<Thuoc> listThuoc)
		{
			this->listThuoc = listThuoc;
		}
		vector<Thuoc> getListThuoc()
		{
			return listThuoc;
		}
		
		void setNoiNhan(string noiNhan)
		{
			this->noiNhan = noiNhan;
		}
		string getNoiNhan()
		{
			return noiNhan;
		}
		
		long long getTongTien()
		{
			return tongTien;
		}

	private:
		void loadDownDTS()
		{
			vector<string> listDT;
			vector<string> listDTS;
			string enter = "\n";
			string tam;
			
			fstream f1;
			f1.open("DonThuoc.txt",ios::in);

			f1.ignore();
			while(!f1.eof())
			{
				getline(f1,tam);
				listDT.push_back(tam);
			}

			
			fstream f2;
			f2.open("DonThuocS.txt",ios::in);
			f2.ignore();
			while(!f2.eof())
			{
				getline(f2,tam);
				if(tam == KhachHang::taiKhoan ){
					
					while(tam != "ketthucDT")
					{
						getline(f2,tam);
					}
				}
				else listDTS.push_back(tam);
			}

			fstream f3;
			f3.open("DonThuocS.txt",ios::out);
			f3<<enter<<KhachHang::taiKhoan;
			for(int i=0; i<listDT.size(); i++)
			{
				f3<<enter<<listDT.at(i);
			}
			f3<<enter<<"ketthucDT";
			for(int i=0; i<listDTS.size(); i++)
			{
				f3<<enter<<listDTS.at(i);
			}
			f1.close();
			f2.close();
			f3.close();
		}
		
		string sinhTime()
		{
			string times="";
			time_t now = time(0);
			char* dt = ctime(&now);
			for(long long i=0; i<19; i++)
			{
				times.push_back(dt[i]);
			}
			return times;
		}
		
		Thuoc getThuocTheoMa(string ma)
		{
			Thuoc mTTam;
			string mT,tTh,lT;
			long long gT;
			fstream f;
			f.open("Thuoc.txt",ios::in);
				while(!f.eof())
				{
					f>>mT; f.ignore(); 
					getline(f,tTh);
					getline(f,lT);
					f>>gT; f.ignore();
					if(mT == ma)
					{
						mTTam.setMaThuoc(mT);
						mTTam.setTenThuoc(tTh);
						mTTam.setLoaiThuoc(lT);
						mTTam.setGiaTien(gT);
						mTTam.showThuoc();
					}
				}
			f.close();
			return mTTam;
		}
	public:
		long long tinhTongTien()
		{
			long long tt=0;

			for(int i=0; i<listThuoc.size(); i++)
			{
				tt += listThuoc.at(i).getGiaTien() * listThuoc.at(i).getSoLuong();
			}
			tongTien = tt;
			return tt;
		}
		
		void taoDT()
		{
			ngayMua = sinhTime();
			string enter = "\n";
			fstream f;
			f.open("DonThuoc.txt",ios::out | ios::app);
			f<<enter<<maDT<<enter<<ngayMua;
			f.close();

			char fileDT[30] = "";
			strcat(fileDT,"DonThuoc/");
			char * tam = new char [maDT.length()+1];
  			strcpy (tam, maDT.c_str());
			strcat(fileDT,tam);
			strcat(fileDT,".txt");
			fstream f1;
			f1.open(fileDT,ios::out | ios::app);
			f1<<ngayMua<<enter;
			f1<<tongTien<<enter;
			f1<<noiNhan<<enter;
			for(int i=0; i<listThuoc.size(); i++)
			{
				f1<<listThuoc.at(i).getMaThuoc()<<enter;
				f1<<listThuoc.at(i).getSoLuong()<<enter;
			}
			f1<<"ketthucDT";
			f1.close();
			loadDownDTS();
		}
		
		vector<string> showDanhSachDT()
		{
			fstream f;
			f.open("DonThuoc.txt",ios::in);
			f.ignore();

			vector<string> listMaDT;
			string maDT, ngayMua;

			cout<<endl<<endl;
			cout<<"  ";
			cout<<setw(20)<< left << "Ma Don Thuoc";
			cout<<setw(35)<< left << "Ngay Dat Mua";
			cout<<endl<<"__________________________________________________";
			cout<<endl<<endl;
			while(!f.eof())
			{
				getline(f,maDT);
				getline(f,ngayMua);
				listMaDT.push_back(maDT);
				cout<<"  ";
				cout<<setw(20)<< left <<maDT;
				cout<<setw(35)<< left <<ngayMua;
				cout<<endl;
				
			}			
			cout<<"__________________________________________________"<<endl;
			
			f.close();
			return listMaDT;
		}
		
		
		vector<Thuoc> showChiTietDT(string maDT)
		{
			vector<Thuoc> dsThuocTrongDon;

			char fileDT[30] = "";
			strcat(fileDT,"DonThuoc/");
			char * tam = new char [maDT.length()+1];
  			strcpy (tam, maDT.c_str());
			strcat(fileDT,tam);
			strcat(fileDT,".txt");
			fstream f1;
			f1.open(fileDT,ios::in);
			
			string ngayMua, noiNhan, tongTien;

			getline(f1,ngayMua);
			getline(f1,tongTien);
			getline(f1,noiNhan);
			

			cout<<endl<<endl;
			cout<<endl<<"  DON THUOC "<<maDT<<endl<<endl;
			cout<<endl<<setw(30)<<left<<"  Ten khach hang : "<<setw(30)<<left<<KhachHang::tenKH<<endl;
			cout<<endl<<setw(30)<<left<<"  Ngay dat hang : "<<setw(30)<<left<<ngayMua<<endl;
			cout<<endl<<setw(30)<<left<<"  Tong gia tri don thuoc : "<<setw(30)<<left<<tongTien<<endl;
			cout<<endl<<setw(30)<<left<<"  Dia chi nhan thuoc : "<<noiNhan<<endl;
			cout<<endl<<endl<<"  Cac Thuoc da dat mua : ";

			cout<<endl<<endl;
			cout<<"  ";
			cout<<setw(8)<< left << "Ma Thuoc";
			cout<<setw(35)<< left << "Ten Thuoc";
			cout<<setw(20)<< left << "Loai";
			cout<<setw(15)<< left << "Gia Tien";
			cout<<"________________________________________________________________________________";
			cout<<endl;

			string maDT1, soLuong;
			while(true)
			{
				f1>>maDT1; if(maDT1 == "ketthucDT") break;
				f1>>soLuong;
				dsThuocTrongDon.push_back(getThuocTheoMa(maDT1));
				cout<<"  So luong : "<<soLuong<<endl<<endl<<endl;

			}
			cout<<"________________________________________________________________________________";
			cout<<endl;
			f1.close();
			return dsThuocTrongDon;
		}
		
};


#endif












