#pragma once
#include"KhaiBao.h"
using namespace std;
class Random //Lớp sinh số ngẫu nhiên
{
private:
	inline static bool _seeded = false;
public:
	int nextInt();
	int nextInt(int ceiling);
	int nextInt(int left, int right);
};
class Tokenizer //Lớp sử dụng cho việc tách chuỗi
{
public:
	static vector<string>split(string haystack, string needle = " ")
	{
		vector<string>result;
		int startPos = 0;
		size_t foundPos = 0;
		while (true)
		{
			foundPos = haystack.find(needle, startPos);
			if (foundPos != string::npos)
			{
				string Token = haystack.substr(startPos, foundPos - startPos);
				result.push_back(Token);
				startPos = foundPos + needle.length();
			}
			else
			{
				string token = haystack.substr(startPos, haystack.length() - startPos);
				result.push_back(token);
				break;
			}
		}
		return result;
	}
};

class HangDienThoai      //Lớp tên hãng điện thoại
{
protected:
	string tenHang;
public:
	string TenHang();
	void NhapTenHang();
	void setTenHang(string value);
	HangDienThoai(string TenHang);
	HangDienThoai();
	~HangDienThoai();
};
class TenSanPham :public HangDienThoai //Lớp Tên Sản Phẩm (Tên Sản phẩm bao gồm phần tên Hãng+ với phần tên đệm(J5,A6,...) + phần đuôi(Plus,Pro...)
{
protected:
	string domain;
	string tail;
public:
	void NhapTen();
	string Domain();
	string Tail();
	TenSanPham(string a, string b, string c);
	TenSanPham();
	static TenSanPham parse(string buffer);
};
class SanPham :public TenSanPham //Lớp Sản Phẩm(bao gồm Tên sản phẩm,số lượng hiện hành của sản phẩm và mã số của sản phẩm(1 số nguyên)
{
protected:
	int soluong;
	int MaSo;
public:
	int Maso();
	SanPham();
	void Nhap();
	SanPham(TenSanPham a, int d, int e);
	int SoLuong();
	static SanPham parse(string buffer);
};
class TenSanPhamMock //Lớp sinh ngẫu nhiên tên sản phẩm
{
private:
	Random rng;
	vector<string>domains;
	vector<string>tails;
	vector<HangDienThoai>Hangs;
public:
	TenSanPhamMock();
	string next();
};
class ChitietSanPham :public SanPham //Lớp Chi tiết của sản phẩm
{
private:
	TenSanPham Tensp;
	string HeDieuHanh;
	string DungLuong;
	int NamSanXuat;
public:
	ChitietSanPham();
	void Nhap();
	ChitietSanPham(TenSanPham a, string b, string c, int d);
	int NamSX();
	string Dung_Luong();
	string He_Dieu_Hanh();
};