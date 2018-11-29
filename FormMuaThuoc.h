#include "DonThuoc.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <ctime>

#ifndef FORMMUATHUOC_H
#define FORMMUATHUOC_H

using namespace std;

class FormMuaThuoc
{
	private:
		KhachHang kH;
		Thuoc Th;
		DonThuoc dT;
	private:
		string sinhMaDT()
		{
			string maDT="";
			time_t now = time(0);
			char* dt = ctime(&now);
			for(long long i=8; i<=19; i++)
			{
				if(dt[i]!=' ' && dt[i]!=':')
					maDT.push_back(dt[i]);
			}
			return maDT;
		}
		
	public:

		long long giaoDienMuaThuoc(vector<Thuoc> listThuoc)
		{
			system("cls");
			cout<<endl<<endl;
			string ma = sinhMaDT();
			cout<<"  DON THUOC "<<ma;
			dT.setMaDT(ma);


			cout<<endl<<endl;
			cout<<"  Ten khach hang: "<<KhachHang::tenKH;

			cout<<endl<<endl;
			cout<<"  Dat mua :";
			cout<<endl<<endl;
			cout<<"  ";
			cout<<setw(8)<< left << "Ma Thuoc";
			cout<<setw(35)<< left << "Ten Thuoc";
			cout<<setw(20)<< left << "Loai";
			cout<<setw(15)<< left << "Gia Tien";
			cout<<"________________________________________________________________________________";
			cout<<endl;

			for(long long i=0; i<listThuoc.size(); i++)
			{
				listThuoc.at(i).showThuoc();
				cout<<"  Nhap so luong: ";
				long long soLuong; cin>>soLuong; 
				listThuoc.at(i).setSoLuong(soLuong);
				cout<<"________________________________________________________________________________";
				cout<<endl<<endl;
			}
			dT.setListThuoc(listThuoc);

			cout<<endl<<endl<<"  Tong tien cua don thuoc la: "<<dT.tinhTongTien();

			cout<<endl<<endl<<endl<<"  Quy khach quyet dinh dat mua thuoc khong:";
			cout<<endl<<endl<<"\t1. Co";
			cout<<endl<<endl<<"\t2. Quay lai";
			string thaoTac;
			do{
				cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
				cin>>thaoTac;
			}while(thaoTac != "1" && thaoTac!="2");
			
			if(thaoTac=="2")return 1;

			cout<<endl<<endl<<"  Nhap noi nhan hang: ";
			string noiNhan;
			fflush(stdin); getline(cin,noiNhan); fflush(stdin);
			dT.setNoiNhan(noiNhan);
			dT.taoDT();

			system("cls");
			cout<<endl<<endl<<"==>\tDAT THUOC THANH CONG ! ";
			string stop;
			getline(cin,stop);
			return 1;


		}
		
};


#endif









