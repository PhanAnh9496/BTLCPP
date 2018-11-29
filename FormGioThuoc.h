//#include "FormMuaThuoc.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <ctime>
#ifndef FORMGIOTHUOC_H
#define FORMGIOTHUOC_H

using namespace std;

class FormGioThuoc
{
	private:
		vector<Thuoc> listThuoc;
		vector<string> listDT;
		Thuoc t;
		DonThuoc dT;
		FormMuaThuoc fmt;
		
	private:
		bool checkMaList(string mT)
		{
			for(long long i=0; i<listThuoc.size(); i++)
			{
				if(listThuoc.at(i).getMaThuoc() == mT) return true;
			}
			return false;
		}
		
		bool checkMaListDT(string dT)
		{
			for(long long i=0; i<listDT.size(); i++)
			{
				if(listDT.at(i) == dT) return true;
			}
			return false;
		}
		
		
	public:

		int giaoDienGioThuoc()
		{
			string chonMenu;
			
			do
			{
				system("cls");
				cout<<endl<<endl;
				cout<<"  Gio Hang ==> "<<KhachHang::tenKH<<endl<<endl<<endl;
				cout<<"\t1. Xem Thuoc Trong Gio"<<endl<<endl;
				cout<<"\t2. Xem Don Thuoc"<<endl<<endl;
				cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
				fflush(stdin); cin>>chonMenu;
			}while(chonMenu!="1" && chonMenu!="2");

				if(chonMenu == "1")
				{
					do
					{
						system("cls");
						cout<<endl<<endl<<" Danh sach hang trong gio: ";
						listThuoc = t.getThuocTrongGio();

						if(listThuoc.size() != 0)
						{
							string x,y;
							
							cout<<endl<<endl<<"\t0. << Menu <<"<<endl;
							cout<<endl<<endl<<"\t1. << Back <<"<<endl;
							cout<<endl<<endl<<"\t2. Mua het"<<endl;
							cout<<endl<<endl<<"\t3. Xoa het"<<endl;
							do
							{
								cout<<endl<<endl<<" [ Nhap MaSP ] ==> [ Enter ] ";
								cin>>x;
							}while(!checkMaList(x) && x!="0" && x!="1" && x!="2" && x!="3");
							
							if(x=="0"){system("cls"); return 0;}
							else if(x=="1"){system("cls"); giaoDienGioThuoc(); return 0;}
							else if(x=="2")
							{
								system("cls"); fmt.giaoDienMuaThuoc(listThuoc);
								t.xoaThuocTrongGio("all");
								continue;
							}
							else if(x=="3")
							{         
								t.xoaThuocTrongGio("all");
								continue;
							}
							cout<<endl<<endl<<"\t0. << Menu <<";
							cout<<endl<<endl<<"\t1. Xem chi tiet ";
							cout<<endl<<endl<<"\t2. Xoa khoi gio thuoc ";
							cout<<endl<<endl<<"\t3. Mua hang";
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
								cout<<endl<<endl<<"\t2. Xoa khoi gio hang ";
								cout<<endl<<endl<<"\t3. Mua hang";
								cout<<endl<<endl<<" [ Nhap So ] ==> [ Enter ]  ";
								cin>>z;
								if(z=="0"){system("cls"); return 0;}
								else if(z=="2")
								{
									t.xoaThuocTrongGio(x);
								}
								else if(z=="3")
								{
									vector<Thuoc> listThuocPhu;
									system("cls"); 
									for(int i=0; i<listThuoc.size(); i++)
									{
										if(listThuoc.at(i).getMaThuoc() == x)
										{
											listThuocPhu.push_back(listThuoc.at(i));
											break;
										}
									}
									fmt.giaoDienMuaThuoc(listThuocPhu);
									t.xoaThuocTrongGio(x);
								}
							}
							else if(y=="2")
							{
								t.xoaThuocTrongGio(x);
							}
							else if(y=="3")
							{
								vector<Thuoc> listThuocPhu3;
								system("cls"); 
								for(int i=0; i<listThuoc.size(); i++)
								{
									if(listThuoc.at(i).getMaThuoc() == x)
									{
										listThuocPhu3.push_back(listThuoc.at(i));
										break;
									}
								}
								fmt.giaoDienMuaThuoc(listThuocPhu3);
								t.xoaThuocTrongGio(x);
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

				else if(chonMenu == "2")
				{
					while(true)
					{
						system("cls");
						cout<<endl<<endl<<" Danh sach don Thuoc: ";	
						listDT = dT.showDanhSachDT();

						if(listDT.size() != 0)
						{
							string x;
							cout<<endl<<endl<<"\t0. << Menu <<"<<endl;
							cout<<endl<<endl<<"\t1. << Back <<"<<endl;
							do
							{
								cout<<endl<<endl<<" [ Nhap Ma Don Thuoc ] ==> [ Enter ] ";
								cin>>x;
							}while(!checkMaListDT(x) && x!="0" && x!="1");

							if(x=="1")
							{
								system("cls");
								giaoDienGioThuoc();
								return 0;
							}
							else if(x=="0") {system("cls"); return 0;}
							else 
							{
								do
								{
									system("cls");
									listThuoc = dT.showChiTietDT(x);
									string y;
									cout<<endl<<endl<<"\t0. << Menu <<"<<endl;
									cout<<endl<<endl<<"\t1. << Back <<"<<endl;
									do
									{
										cout<<endl<<endl<<" [ Nhap Ma Thuoc ] ==> [ Enter ] ";
										cin>>y;
									}while(!checkMaList(y) && y!="0" && y!="1");

									if(y=="0"){system("cls"); return 0;}
									else if(y=="1"){system("cls");  break;} 
									{
										system("cls");
										t.showChiTiet(y);
										string stop;
										cout<<endl<<endl<<endl<<endl<<"\t[ Enter ] ==> Quay Lai\t";
										fflush(stdin);getline(cin,stop);fflush(stdin);
									}

								}while(true);

							}

						}
						else 
						{
								string stop;
								cout<<endl<<endl<<endl<<endl<<"\t[ Enter ] ==> Quay Lai\t";
								fflush(stdin);getline(cin,stop);fflush(stdin);
								system("cls"); return 0;
						}	
					}

				}	
		}
		
};

#endif












