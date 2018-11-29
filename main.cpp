#include <iostream>
#include <string>
#include "FormChinh.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


bool KhachHang::daDangNhap = false;
string KhachHang::tenKH = "";
string KhachHang::taiKhoan = "";

int main(int argc, char** argv) {
	
	FormChinh fc;
	fc.manKhoiDong();
	
	return 0;
}
