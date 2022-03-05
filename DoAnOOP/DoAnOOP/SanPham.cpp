#include"KhaiBao.h"
#include"SanPham.h"
#include<vector>
using namespace std;
#include<string>
int Random::nextInt()
{
	if (!_seeded)
	{
		srand(time(NULL));
		_seeded = true;
	}
	return rand();
}
int Random::nextInt(int ceiling)
{
	if (!_seeded)
	{
		srand(time(NULL));
		_seeded = true;
	}
	return nextInt() % ceiling;
}
int Random::nextInt(int left, int right)
{
	if (!_seeded)
	{
		srand(time(NULL));
		_seeded = true;
	}
	return nextInt() % (right - left + 1) + left;
}
string HangDienThoai::TenHang() //Trả về tên Hãng
{
	return tenHang;
}
void HangDienThoai::NhapTenHang()
{
	cout << "Nhap ten hang dien thoai:";
	cin.ignore();
	cin >> tenHang;
}
void HangDienThoai::setTenHang(string value)
{
	tenHang = value;
}
HangDienThoai::HangDienThoai(string TenHang)
{
	tenHang = TenHang;
}
HangDienThoai::HangDienThoai() {}
HangDienThoai::~HangDienThoai() {}
void TenSanPham::NhapTen() //Nhập tên Sản Phẩm từ bàn phím
{
	HangDienThoai::NhapTenHang();
	while (getchar() != '\n');
	cout << "Nhap vao ten dem :";
	cin >> domain;
	while (getchar() != '\n');
	cout << "Nhap vao duoi san pham :";
	cin >> tail;
}
string TenSanPham::Domain()
{
	return domain;
}
string TenSanPham::Tail()
{
	return tail;
}
TenSanPham::TenSanPham(string a, string b, string c)
{
	tenHang = a;
	domain = b;
	tail = c;
}
TenSanPham::TenSanPham() {}
TenSanPham TenSanPham::parse(string buffer) //Tách chuỗi để lấy giá trị tên hãng,domain,tail
{
	vector<string> tokens = Tokenizer::split(buffer, " "); //Các thành phần tên sản phẩm tách nhau bởi khoảng trắng
	string a = tokens[0];
	string b = tokens[1];
	string c = tokens[2];
	TenSanPham result = TenSanPham(a, b, c);
	return result;
}
SanPham::SanPham()
{
	MaSo = 0;
	soluong = 0;
}
int SanPham::Maso()
{
	return MaSo;
}
void SanPham::Nhap() //Nhập sản phẩm từ bàn phím
{
	TenSanPham::NhapTen();
	cout << " Nhap vao so luong ";
	cin >> soluong;
	cout << " Nhap vao Ma So ";
	cin >> MaSo;
}
SanPham::SanPham(TenSanPham a, int d, int e)
{
	tenHang = a.TenHang();
	domain = a.Domain();
	tail = a.Tail();
	soluong = d;
	MaSo = e;
}
int SanPham::SoLuong()
{
	return soluong;
}
SanPham SanPham::parse(string buffer) //Hàm tách chuỗi để lấy các giá trị tên Hãng,domain,tail,số lượng và mã số sản phẩm
{
	vector<string> tokens = Tokenizer::split(buffer, ","); //Các thành phần của lớp SanPham sẽ tách nhau bởi dấu phẩy
	TenSanPham a = TenSanPham::parse(tokens[0]);
	int n = stoi(tokens[1]);
	int m = stoi(tokens[2]);
	SanPham result = SanPham(a, n, m);
	return result;
}
TenSanPhamMock::TenSanPhamMock() //Lấy ra 3 mảng để có dữ liệu phục vụ sinh số ngẫu nhiên
{
	ifstream reader("HangDienThoai.txt"); //Mảng tên Hãng được đọc từ file("HangDienThoai.txt") đã lưu từ trước 
	while (!reader.eof())
	{
		string line;
		getline(reader, line);
		HangDienThoai x;
		x.setTenHang(line);
		Hangs.push_back(x);
	}
	reader.close();
	domains = { "5","6","7","8","9","X","J5","J6","J7","J8","A5","A6","A7","A8","A9" }; //Mảng domain
	tails = { "Plus","S","Max","Pro" }; //Mảng tail
}
string TenSanPhamMock::next()
{
	int i = rng.nextInt(Hangs.size());
	HangDienThoai Ten;
	Ten.setTenHang(Hangs[i].TenHang()); //Lấy ngẫu nhiên tên hãng
	int j = rng.nextInt(domains.size());
	string domain = domains[j]; //Lấy ngẫu nhiên domain
	int k = rng.nextInt(tails.size()); //Lấy ngẫu nhiên tail
	string tail = tails[k];
	string number = to_string(rng.nextInt(6, 20)); //Lấy ngẫu nhiên số lượng
	stringstream writer;
	writer << Ten.TenHang() << " " << domain << " " << tail << "," << number;
	string result = writer.str();
	return result;
}
ChitietSanPham::ChitietSanPham()
{
	NamSanXuat = 0;
	HeDieuHanh = "";
	DungLuong = "";
	TenSanPham a;
}
void ChitietSanPham::Nhap() //Nhập từ bàn phím các chi tiết sản phẩm
{
	SanPham::Nhap();
	while (getchar() != '\n');
	cout << "Nhap He Dieu Hanh :";
	cin >> HeDieuHanh;
	while (getchar() != '\n');
	cout << "Nhap Dung Luong :";
	cin >> DungLuong;
	cout << "Nhap Nam San Xuat :";
	cin >> NamSanXuat;
}
ChitietSanPham::ChitietSanPham(TenSanPham a, string b, string c, int d)
{
	NamSanXuat = d;
	Tensp = a;
	DungLuong = b;
	HeDieuHanh = c;
}
int ChitietSanPham::NamSX()
{
	return NamSanXuat;
}
string ChitietSanPham::Dung_Luong()
{
	return DungLuong;
}
string ChitietSanPham::He_Dieu_Hanh()
{
	return HeDieuHanh;
}
