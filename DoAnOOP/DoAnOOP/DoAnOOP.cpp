// DoAnOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"KhaiBao.h"
#include"SanPham.h"
using namespace std;
void MenuNhapTenHang() //Hàm nhập tên hãng và lưu thông tin
{
	vector<HangDienThoai>Hang;
	while (true)
	{
		system("cls");
		cout << "===============MENU NHAP TEN HANG===========" << endl;
		cout << "======1:NHAP TEN HANG============" << endl;
		cout << "======2:XOA TEN HANG============" << endl;
		cout << "======3:SUA TEN HANG============" << endl;
		cout << "======4:XUAT TEN HANG============" << endl;
		cout << "======5:SAO LUU TEN HANG============" << endl; // Được lưu ở file HangDienThoai.txt
		cout << "======0:THOAT============" << endl;
		int chon;
		cout << "Chon lua chon cua ban = ";
		cin >> chon;
		if (chon == 1)
		{
			int n = 0;
			HangDienThoai x;
			x.NhapTenHang();
			Hang.push_back(x);
			n++;
		}
		else if (chon == 2) //Thao tác xóa tên hãng
		{
			string a;
			cout << "Nhap hang dien thoai muon xoa :";
			cin.ignore();
			getline(cin, a);
			for (int i = 0;i < Hang.size(); i++)
			{
				if (Hang[i].TenHang() == a)
				{
					Hang.erase(Hang.begin() + i);
				}
			}
		}
		else if (chon == 3) //Thao tác sửa tên hãng
		{
			string a;
			string b;
			cout << "Nhap hang dien thoai muon sua : ";
			cin >> a;
			cout << "Nhap hang dien thoai muon sua thanh : ";
			cin >> b;
			for (int i = 0;i < Hang.size(); i++)
			{
				if (Hang[i].TenHang() == a)
				{
					Hang[i].setTenHang(b);
				}
			}
		}
		else if (chon == 4) //Xem trước tên hãng
		{
			for (int i = 0;i < Hang.size();i++)
			{
				cout << Hang[i].TenHang() << endl;

			}
			system("pause");
		}
		else if (chon == 5) //Nếu xem trước đã ổn rồi lưu vào file ("HangDienThoai.txt")
		{
			ofstream writter("HangDienThoai.txt");
			cout << "Da luu danh sach ten Hang thanh cong" << endl;
			for (int i = 0;i < Hang.size() - 1;i++)
			{
				writter << Hang[i].TenHang() << endl;
			}
			writter << Hang[Hang.size() - 1].TenHang();
			writter.flush();
			writter.close();
			system("pause");
		}
		else if (chon == 0) //Thoat vong lap
		{
			break;
		}
	}
}
void XuatChiTiet(vector<ChitietSanPham>a) //Hàm xuất các chi tiết sản phẩm riêng biệt
{
	for (int i = 0;i < a.size();i++)
	{
		cout << "San pham thu " << i + 1 << endl;
		cout << "Ten Hang : " << a[i].TenHang() << endl;
		cout << "Ten San Pham: " << a[i].TenHang() << " " << a[i].Domain() << " " << a[i].Tail() << endl;
		cout << "So luong: " << a[i].SoLuong() << endl;
		cout << "He Dieu Hanh: " << a[i].He_Dieu_Hanh() << endl;
		cout << "Dung Luong: " << a[i].Dung_Luong() << endl;
		cout << "Nam San Xuat: " << a[i].NamSX() << endl;
	}
}
void MenuSanPham()
{
	vector<string>danhsach;
	Random rng;
	vector<ChitietSanPham>ChiTiets;
	while (1)
	{
		system("cls");
		cout << "===============MENU XEM DANH SACH SAN PHAM===========" << endl;
		cout << "======1:TAO DU LIEU AO DANH SACH SAN PHAM============" << endl;
		cout << "======2:XEM DANH SACH SAN PHAM THEO HANG SAN XUAT============" << endl;
		cout << "======3:THAO TAC VOI THONG TIN CHI TIET CUA DIEN THOAI============" << endl;
		cout << "======0:THOAT============" << endl;
		int chon;
		cout << "Chon lua chon cua ban = ";
		cin >> chon;
		if (chon == 1)
		{
			TenSanPhamMock sanphamStore; //Nếu chọn bằng 1 sẽ tự động phát sinh các danh sách sản phẩm từ lớp TenSanPhamMock
			int n = rng.nextInt(10, 15);
			for (int i = 0;i < n;i++)
			{
				string sp = sanphamStore.next();
				danhsach.push_back(sp);
			}
			ofstream writter("DanhSachSanPham.txt");
			cout << "Da luu danh sach san pham thanh cong" << endl;
			for (int i = 0;i < danhsach.size() - 1;i++)
			{
				writter << danhsach[i] << "," << 9 + i + 1 << endl; //Phát sinh thêm mã số sản phẩm chạy lần lượt từ 10 và tăng theo cấp số cộng công sai là 1
			}
			writter << danhsach[danhsach.size() - 1] << "," << 9 + danhsach.size();
			writter.flush();
			writter.close();
			system("pause");
		}
		else if (chon == 2) //Xem danh sách sản phẩm 
		{
			vector<SanPham>Danhsachsanpham;
			vector<string>a;
			vector<HangDienThoai>hangs;
			ifstream reader("DanhSachSanPham.txt"); //Đọc file "DanhSachSanPham.txt vào 1 mảng string là line"
			while (!reader.eof())
			{
				string line;
				getline(reader, line);
				a.push_back(line);
			}
			for (int i = 0;i < a.size(); i++) //tiến hành lấy thông tin sản phẩm
			{
				SanPham b = SanPham::parse(a[i]);
				Danhsachsanpham.push_back(b);
			}
			ifstream reader1("HangDienThoai.txt"); //Lấy thông tin Hãng phục vụ cho việc xuất sản phẩm theo hãng
			while (!reader1.eof())
			{
				string buffer;
				getline(reader1, buffer);
				HangDienThoai x;
				x.setTenHang(buffer);
				hangs.push_back(x);
			}
			reader1.close();
			for (int l = 0;l < hangs.size();l++) //Xuất thông tin sản phẩm ra màn hình console
			{
				cout << hangs[l].TenHang() << endl;
				for (int j = 0;j < Danhsachsanpham.size();j++)
				{
					if (hangs[l].TenHang() == Danhsachsanpham[j].TenHang())
					{
						cout << Danhsachsanpham[j].TenHang() << " " << Danhsachsanpham[j].Domain() << " " << Danhsachsanpham[j].Tail() << "/So luong: " << Danhsachsanpham[j].SoLuong() << "/Ma so: " << Danhsachsanpham[j].Maso() << endl;
					}
				}
			}
			system("pause");
		}
		else if (chon == 3) //Nhập thông tin chi tiết của 1 sản phẩm
		{
			while (1)
			{
				system("cls");
				cout << "===============MENU NHAP THONG TIN CHI TIET SAN PHAM===========" << endl;
				cout << "======1:NHAP THONG TIN CHI TIET CUA DIEN THOAI============" << endl;
				cout << "======2:XOA THONG TIN CUA DIEN THOAI============" << endl;
				cout << "======3:XUAT THONG TIN CHI TIET CUA DIEN THOAI============" << endl;
				cout << "======4:LUU THONG TIN CHI TIET CUA DIEN THOAI============" << endl;
				cout << "======0:THOAT============" << endl;
				int chon;
				cout << "Chon so thu tu ma ban muon thao tac :";
				cin >> chon;
				if (chon == 1) //Nhập thông tin chi tiết 
				{
					ChitietSanPham x;
					x.Nhap();
					ChiTiets.push_back(x);
				}
				else if (chon == 3) //Xem thông tin chi tiết
				{
					XuatChiTiet(ChiTiets);
					system("pause");
				}
				else if (chon == 2) //Nên xem thông tin chi tiết trước rồi nhập số thứ tự của sản phẩm muốn xóa rồi nhập số thứ tự vào
				{
					int m;
					cout << "Chon so thu tu cua san pham ban muon xoa :";
					cin >> m;
					ChiTiets.erase(ChiTiets.begin() + (m - 1));
					cout << "Thong tin san pham da duoc xoa ";
					system("pause");
				}
				else if (chon == 4) //Lưu danh sách chi tiết sản phẩm vào file ("DanhSachChiTietSanPham.txt")
				{
					ofstream writter("DanhSachChiTietSanPham.txt");
					cout << "Da luu danh sach chi tiet san pham thanh cong" << endl;
					for (int i = 0;i < ChiTiets.size();i++)
					{
						writter << "San pham thu " << i + 1 << endl;
						writter << "Ten Hang : " << ChiTiets[i].TenHang() << endl;
						writter << "Ten San Pham: " << ChiTiets[i].TenHang() << " " << ChiTiets[i].Domain() << " " << ChiTiets[i].Tail() << endl;
						writter << "So luong: " << ChiTiets[i].SoLuong() << endl;
						writter << "He Dieu Hanh: " << ChiTiets[i].He_Dieu_Hanh() << endl;
						writter << "Dung Luong: " << ChiTiets[i].Dung_Luong() << endl;
						writter << "Nam San Xuat: " << ChiTiets[i].NamSX() << endl;
					}
					writter.close();
					system("pause");
				}
				else if (chon == 0)
				{
					break;
				}
			}
		}
		else if (chon == 0)//Thoát
		{
			break;
		}
	}
}
class MaSoMock //Lớp sinh số ngẫu nhiên các mã đơn hàng(Thứ tự là 2 kí tự đầu biểu hiện cho mặt hàng của tháng nào,2 kí tự tiếp là mã số của sản phẩm
{               //3 kí tự tiếp theo sinh ngẫu nhiên từ các kí tự đã có và kí tự cuối cùng là sinh số ngẫu nhiên 1 số từ 1 tới 9
private:
	vector<int>So;
	Random rng;
	vector<string>Domains;
	vector<string>Tails;
public:
	MaSoMock() //Lấy ra 3 mảng phục vụ cho việc sinh số ngẫu nhiên
	{
		vector<SanPham>SanPhams; //Mảng đầu tiên là mảng mã số sản phẩm được đọc từ file "DanhSachSanPham.txt" 
		vector<string>Temp1;
		ifstream read("DanhSachSanPham.txt");
		while (!read.eof())
		{
			string line;
			getline(read, line);
			Temp1.push_back(line);
		}
		read.close();
		for (int i = 0;i < Temp1.size();i++)
		{
			SanPham a = SanPham::parse(Temp1[i]);
			SanPhams.push_back(a);
		}
		for (int i = 0;i < SanPhams.size();i++)
		{
			So.push_back(SanPhams[i].Maso());
		}
		Domains = { "ABC","BDC","CEF","DEC" }; //Mảng domain( 3 kí tự kế cuối)
		Tails = { "1","2","3","4","5","6","7","8","9" };//Mảng tail(kí tự cuối)
	}
	string next(int i) //Sinh số ngẫu nhiên mã đơn hàng( tham số đầu vào là số thứ tự tháng trong năm nên đây là 1 số nguyên)
	{
		string head; //head được cấu thành từ tháng nên tháng nào >10 sẽ không cộng chuỗi 0 còn nếu <10 sẽ cộng chuỗi 0
		if (i < 10)
		{
			head = "0" + to_string(i);
		}
		else
		{
			head = to_string(i);
		}
		int j = rng.nextInt(Domains.size());
		string domain = Domains[j]; //Lấy ngẫu nhiên 1 domain
		int k = rng.nextInt(Tails.size());
		string tail = Tails[k]; //Lấy ngẫu nhiên 1 tail
		int l = rng.nextInt(So.size());
		string number = to_string(So[l]); //Lấy ngẫu nhiên 1 mã số sản phẩm 
		stringstream writer;
		writer << head << number << domain << tail; //Hoàn chỉnh
		string result = writer.str();
		return result;
	}
};
class ChiTietDonHang :public TenSanPham //lớp Chi tiết đơn hàng sẽ gồm có mã đơn hàng,tên sản phẩm,mã số sản phẩm,đơn giá, ngày xuất xưởng và số lượng được đưa đi
{
private:
	string MaDonHang;
	int MaSo;
	long int DonGia;
	string NgayDi;
	int soLuong;
public:
	ChiTietDonHang()
	{
		MaDonHang = "";
		MaSo = 0;
		DonGia = 0;
		NgayDi = "";
		soLuong = 0;
	}
	ChiTietDonHang(TenSanPham f, string a, int b, long int c, string d, int e)
	{
		tenHang = f.TenHang();
		domain = f.Domain();
		tail = f.Tail();
		MaDonHang = a;
		MaSo = b;
		DonGia = c;
		NgayDi = d;
		soLuong = e;
	}
	string maDonHang()
	{
		return MaDonHang;
	}
	int maSo()
	{
		return MaSo;
	}
	long int donGia()
	{
		return DonGia;
	}
	int SoLuong()
	{
		return soLuong;
	}
	string ngayDi()
	{
		return NgayDi;
	}
	static ChiTietDonHang parse(string buffer) //Hàm tách chuỗi để lấy các thành phần trong 1 chi tiết sản phẩm
	{
		vector<string> tokens = Tokenizer::split(buffer, ","); //Tách nhau bởi dấu phẩy
		TenSanPham f = TenSanPham::parse(tokens[2]);
		string a = tokens[0];
		int b = stoi(tokens[1]);
		long int c = stoi(tokens[3]);
		string d = tokens[4];
		int e = stoi(tokens[5]);
		ChiTietDonHang result = ChiTietDonHang(f, a, b, c, d, e);
		return result;
	}
};
class ChiTietDonHangMock //Lớp sinh số ngẫu nhiên chi tiết đơn hàng 
{
private:
	vector<SanPham>SanPhams;
	vector<long int>DonGias;
	Random rng;
public:
	ChiTietDonHangMock() //Mảng để lấy thông tin sản phẩm,cụ thể hơn là để lấy tên sản phẩm
	{
		vector<string>Temp1;
		ifstream read("DanhSachSanPham.txt");
		while (!read.eof())
		{
			string line;
			getline(read, line);
			Temp1.push_back(line);
		}
		read.close();
		for (int i = 0;i < Temp1.size();i++)
		{
			SanPham a = SanPham::parse(Temp1[i]);
			SanPhams.push_back(a);
		}
		DonGias = { 4000000,5000000,6000000 }; //Mảng ngẫu nhiên đơn giá sẽ có 3 giá được phát ngẫu nhiên cho từng sản phẩm
	}
	string next(string buffer) //hàm phát sinh ngẫu nhiên chi tiết sản phẩm từ 1 mã đơn hàng đã có sẵn
	{
		string Ten;
		string head = buffer;  //Lấy mã đơn hàng chính bằng tham số đầu vào
		string ms = buffer.substr(2, 2); //Mã số được lấy từ 2 kí tự tiếp theo bỏ qua 2 kí tự đầu
		int i = rng.nextInt(DonGias.size());
		for (int j = 0;j < SanPhams.size();j++)
		{
			if (SanPhams[j].Maso() == atoi(ms.c_str()))
			{
				Ten = SanPhams[j].TenHang() + " " + SanPhams[j].Domain() + " " + SanPhams[j].Tail(); //Lấy tên sản phẩm kết từ 3 thành phần và lấy ngẫu nhiên 1 tên sản phẩm
			}
		}
		string gia = to_string(DonGias[i]); //Lấy ngẫu nhiên 1 đơn giá
		string soluong = to_string(rng.nextInt(1, 3)); //Lấy ngẫu nhiên 1 số để làm số lượng
		string ngay = to_string(rng.nextInt(1, 28)); //Lấy ngẫu nhiên ngày chỉ chạy từ 1 đến 28(Lưu ý:Không quá chú trọng thông tin này)
		string thang = buffer.substr(0, 2); //Thông tin này lấy từ 2 kí tự đầu của mã đơn hàng
		stringstream writer;
		writer << head << "," << ms << "," << Ten << "," << gia << "," << ngay << "/" << thang << "/" << "2021" << "," << soluong; //Hoàn chỉnh
		string result = writer.str();
		return result;
	}
};
void MenuXemDonHang() //Hàm xem thông tin đơn hàng
{
	while (1)
	{
		system("cls");
		cout << "===============MENU DANH SACH DON HANG===========" << endl;
		cout << "======1:XEM DANH SACH DON HANG THEO THANG ( THEO MA DON HANG )============" << endl;
		cout << "======2:XEM CHI TIET DON HANG============" << endl;
		cout << "======0:THOAT============" << endl;
		int chon;
		cout << "Chon su lua chon cua ban : ";
		cin >> chon;
		if (chon == 1) //Phát sinh ngẫu nhiên mã đơn hàng(Thông tin này lúc này chưa cần để xuất ra màn hình)
		{
			vector<string>Temp;
			int n = 1;
			ofstream out("MaSanPham.txt");
			MaSoMock MaSoStore;
			for (int i = 0;i < 12;i++)  //Chạy từ 0 đến 11 để lấy số thứ tự tháng
			{
				for (int j = 0;j < 5;j++)
				{
					string a = MaSoStore.next(i + 1); //Sinh số ngẫu nhiên mã đơn hàng và ghi ra file("MaSanPham.txt")
					out << a << endl;
					if (i == 12)
					{
						if (j == 3)
						{
							break;
						}
					}
				}
			}
			out << MaSoStore.next(12); //Tách vị trí cuối ra riêng
			out.flush();
			out.close();
			ifstream reader("MaSanPham.txt"); //Đọc lại file ("MaSanPham.txt")
			while (!reader.eof())
			{
				string line;
				getline(reader, line);
				Temp.push_back(line);
			}
			reader.close();
			cout << "Danh sach ma dơn hang theo thang" << endl;
			while (n <= 12) //Xuất danh sách mã đơn hàng theo từng tháng 1
			{
				cout << "Thang" << " " << n << endl;
				for (int j = 0;j < Temp.size();j++)
				{
					string temp = Temp[j].substr(0, 2);
					if (atoi(temp.c_str()) == n)
					{
						cout << Temp[j] << ",";
					}
				}
				cout << endl;
				cout << "===================================================================================";
				n++;
				cout << endl;
			}
			ChiTietDonHangMock ChiTietDonHangStore; //Sinh số ngẫu nhiên Chi tiết sản phẩm và ghi ra file ("ChiTietDonHang.txt")
			ofstream Out("ChiTietDonHang.txt");
			for (int i = 0;i < Temp.size() - 1;i++)
			{
				Out << ChiTietDonHangStore.next(Temp[i]) << endl;
			}
			Out << ChiTietDonHangStore.next(Temp[Temp.size() - 1]);
			Out.flush();
			Out.close();
			system("pause");
		}
		else if (chon == 2)
		{
			vector<string>Temp1;
			vector<ChiTietDonHang>CTDH;
			string ma;
			ifstream read("ChiTietDonHang.txt"); //Đọc lại file ("ChiTietSanPham.txt")
			while (!read.eof())
			{
				string line;
				getline(read, line);
				Temp1.push_back(line);
			}
			read.close();
			for (int i = 0;i < Temp1.size();i++) //Lấy thông tin các thàng phần 
			{
				ChiTietDonHang a = ChiTietDonHang::parse(Temp1[i]);
				CTDH.push_back(a);
			}
			cout << "Moi ban nhap vao Ma don Hang ma ban muon xem chi tiet "; //Xem đơn hàng 1 cách chi tiết bằng cách nhập mã đơn hàng(Nên lấy từ file ("ChiTietSanPham.txt")) để nhập và kiểm tra
			cin >> ma;
			for (int i = 0;i < CTDH.size();i++)
			{
				if (CTDH[i].maDonHang() == ma)
				{
					cout << "Ma Don Hang :" << CTDH[i].maDonHang() << endl;
					cout << "Ma So San Pham :" << CTDH[i].maSo() << endl;
					cout << "Ten San Pham :" << CTDH[i].TenHang() << " " << CTDH[i].Domain() << " " << CTDH[i].Tail() << endl;
					cout << "Don Gia :" << CTDH[i].donGia() << endl;
					cout << "Ngay Duoc Mua :" << CTDH[i].ngayDi() << endl;
					cout << "So Luong :" << CTDH[i].SoLuong() << endl;
				}
			}
			system("pause");
		}
		else if (chon == 0)
		{
			break;
		}
	}
}
int max(vector<int>a) //Hàm tìm phần tử lớn nhất trong mảng
{
	int m = a[0];
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > m)
			m = a[i];
	}
	return m;
}
ChiTietDonHang TraVeDonHang(vector< ChiTietDonHang>Temps, int m) //1 Hàm phụ phục vụ cho việc tìm sản phẩm bán chạy nhất trong tháng
{
	vector<int>b; //Hàm này sẽ trả về vị trí Chi Tiết Đơn hàng cần thiết tại vị trí m 
	vector<int>c;
	ChiTietDonHang f;
	for (int i = 0;i < Temps.size();i++)
	{
		b.push_back(1);
	}
	for (int i = 0;i < Temps.size();i++) //Đếm số lần lặp của từng sản phẩm
	{
		int y = Temps[i].maSo();
		int dem1 = 1;
		if (b[i]) {
			b[i] = 0;
			for (int j = i + 1;j < Temps.size();j++)
			{
				if (y == Temps[j].maSo())
				{
					dem1++;
					b[j] = 0;
				}
			}
			if (Temps[i].SoLuong() * dem1 == m) //Lấy số lần trùng nhân với số lượng của sản phẩm
			{
				f = Temps[i];
			}
		}
	}
	return f;
}
vector<ChiTietDonHang> SanPhamBanChay(vector< ChiTietDonHang>Temps) //Hàm trả về những sản phẩm bán chạy 
{
	vector<int>b;
	vector<int>c;
	vector<ChiTietDonHang>f;
	for (int i = 0;i < Temps.size();i++) //Mảng b flags đánh dấu đã kiểm tra hay chưa 
	{
		b.push_back(1);
	}
	for (int i = 0;i < Temps.size();i++) //Mảng để lấy số lượng của tất cả các đơn hàng
	{
		c.push_back(Temps[i].SoLuong());
	}
	vector<int>number;
	int l = max(c); //Tìm số lượng lớn nhất trong tất cả các đơng hàng
	for (int i = 0;i < Temps.size();i++)
	{
		int n = Temps[i].maSo();
		int dem = 1;
		if (b[i]) {
			b[i] = 0;
			for (int j = i + 1;j < Temps.size();j++)
			{
				if (n == Temps[j].maSo())
				{
					dem++;
					b[j] = 0;
				}
			}
			number.push_back(dem * Temps[i].SoLuong()); //Mảng number sẽ lấy số lượng của từng sản phẩm một=số lần lặp*số lượng tương ứng
		}
	}
	int m = max(number); //Tìm số lớn nhất trong danh sách số lượng từng sản phẩm vừa lấy ở trên
	if (m <= l) //Nếu như tổng số lượng từng sản phẩm lớn nhất(m) nhỏ hơn hoặc bằng số lớn nhất vừa tìm được trong mảng số lượng các sản phẩm(l)
	{
		for (int i = 0;i < Temps.size();i++)
		{
			if (Temps[i].SoLuong() == l)
			{
				f.push_back(Temps[i]); //Sẽ lấy phần tử chi tiết sản phẩm có số lượng bằng với l
			}
		}
	}
	if (m > l) //Còn nếu lớn hơn
	{
		ChiTietDonHang a = TraVeDonHang(Temps, m); //Lấy phần từ mà có vị trí đó có số lượng sản phẩm bằng với m
		f.push_back(a);
	}
	return f;
}
void MenuBaoCaoDoanhThu() //Hàm xuất ra báo cáo doanh thu
{
	vector<ChiTietDonHang>ChiTiet;
	vector<SanPham>sanPham;
	vector<string>temp1;
	ifstream reader("ChiTietDonHang.txt"); //Đọc file ("ChiTietDonHang.txt")
	while (!reader.eof())
	{
		string line;
		getline(reader, line);
		ChiTietDonHang ct = ChiTietDonHang::parse(line);
		ChiTiet.push_back(ct);
	}
	reader.close();
	vector<string>temp;
	ifstream reader1("DanhSachSanPham.txt"); //Đọc file ("DanhSachSanPham.txt")
	while (!reader1.eof())
	{
		string line1;
		getline(reader1, line1);
		temp.push_back(line1);
	}
	reader1.close();
	for (int i = 0;i < temp.size();i++)
	{
		SanPham a = SanPham::parse(temp[i]);
		sanPham.push_back(a);
	}
	while (1)
	{
		system("cls");
		cout << "===============MENU BAO CAO DOANH THU===========" << endl;
		cout << "======1:XEM DANH SACH SAN PHAM SAP HET (<10)============" << endl;
		cout << "======2:XEM DOANH THU CUA MOT THANG CU THE===========" << endl;
		cout << "======3:XEM MAT HANG NAO BAN CHAY VAO THANG TRUOC============" << endl;
		cout << "======0:THOAT============" << endl;
		int chon;
		cout << "Chon su lua chon cua ban = ";
		cin >> chon;
		if (chon == 1)
		{
			cout << "Danh sach san pham sap het (<10)" << endl; //Nếu đọc trong file ("DanhSachSanPham.txt") mà có số lượng sản phẩm nào <10 xuất ra sản phẩm đó
			for (int i = 0;i < sanPham.size();i++)
			{
				if (sanPham[i].SoLuong() < 10)
				{
					cout << sanPham[i].TenHang() << " " << sanPham[i].Domain() << " " << sanPham[i].Tail() << "/So luong :" << sanPham[i].SoLuong() << endl;
				}
			}
			system("pause");
		}
		if (chon == 2)
		{
			int thang;
			cout << "Nhap vao thang ma ban muon xem doanh thu "; //Nhập số thứ tự tháng
			cin >> thang;
			int tong = 0;
			for (int i = 0;i < ChiTiet.size();i++)
			{
				string a = ChiTiet[i].maDonHang();
				if (atoi(a.substr(0, 2).c_str()) == thang) //Chuyển sang kiểu int 2 kí tự đầu và so với số thứ tự tháng vừa nhập
				{
					tong = tong + ChiTiet[i].donGia() * ChiTiet[i].SoLuong(); //Nếu tìm được thì sẽ theo công thức đơn giá*số lượng và cộng dồn sẽ ra được doanh thu
				}
			}
			cout << "Doanh thu cua thang " << thang << " = " << tong << endl;
			system("pause");
		}
		if (chon == 3)
		{
			int thang;
			cout << "Nhap vao thang hien tai (>1) "; //Nhập vào tháng hiện tại
			cin >> thang;
			vector<ChiTietDonHang>Temps; //Trích ra mảng nhỏ hơn để dễ xử lý (Mảng này chứa sản phẩm có số thứ tự tháng nhỏ hơn tháng vừa nhập 1 đơn vị
			for (int i = 0;i < ChiTiet.size();i++) //Do đề yêu cầu tháng trước
			{
				string a = ChiTiet[i].maDonHang();
				if (atoi(a.substr(0, 2).c_str()) == (thang - 1))
				{
					if (atoi(a.substr(2, 2).c_str()) == ChiTiet[i].maSo())
					{
						Temps.push_back(ChiTiet[i]);
					}
				}
			}
			vector<ChiTietDonHang>f = SanPhamBanChay(Temps); //Áp dụng hàm đã sử dụng ở trên
			cout << "Mat hang ban chay vao thang " << thang - 1 << " co thong tin sau :" << endl; //Xuất thông tin
			for (int i = 0;i < f.size();i++)
			{
				cout << "Ma Don Hang :" << f[i].maDonHang() << endl;
				cout << "Ma So San Pham :" << f[i].maSo() << endl;
				cout << "Ten San Pham :" << f[i].TenHang() << " " << f[i].Domain() << " " << f[i].Tail() << endl;
				cout << "Don Gia :" << f[i].donGia() << endl;
			}
			system("pause");
		}
	}
}
int main()
{
	while (true)
	{
		system("cls");
		cout << "===============MENU CUA HANG DIEN THOAI===========" << endl;
		cout << "======1:NHAP DANH SACH TEN HANG DIEN THOAI============" << endl;
		cout << "======2:XEM DANH SACH SAN PHAM CUA CUA HANG============" << endl;
		cout << "======3:XEM DANH SACH DON HANG CUA CUA HANG============" << endl;
		cout << "======4:XEM BAO CAO DOANH THU CUA CUA HANG============" << endl;
		cout << "======0:THOAT============" << endl;
		int chon;
		cout << "Chon su lua chon cua ban = ";
		cin >> chon;
		if (chon == 1)
		{
			MenuNhapTenHang();
		}
		else if (chon == 2)
		{
			MenuSanPham();
		}
		else if (chon == 3)
		{
			MenuXemDonHang();
		}
		else if (chon == 4)
		{
			MenuBaoCaoDoanhThu();
		}
		else if (chon == 0)
		{
			break;
		}
	}
}


