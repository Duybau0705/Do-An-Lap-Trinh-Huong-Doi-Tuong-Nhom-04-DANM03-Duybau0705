#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Sach{
	protected:
		string MaSoSach,TenSach,ChuDe,TacGia,NhaXuatBan,NgayThangNamXuatBan;
		int SoTrang,SoBanLuuThuVien;
	public:
		void DocThongTinSach(ifstream &DocFile){
			getline(DocFile, MaSoSach, '#');	
			getline(DocFile, TenSach, '#');
			getline(DocFile, ChuDe, '#');
			getline(DocFile, TacGia, '#');
			getline(DocFile, NhaXuatBan, '#');
			getline(DocFile, NgayThangNamXuatBan, '#');
			string a;
			DocFile>>SoTrang;
			getline(DocFile, a, '#');
			DocFile>>SoBanLuuThuVien;
			getline(DocFile, a, '#');
		}
		void XuatSach(){
			cout<<"Ma so sach: "<<MaSoSach<<endl;
			cout<<"Ten sach: "<<TenSach<<endl;
			cout<<"Chu de: "<<ChuDe<<endl;
			cout<<"Tac gia: "<<TacGia<<endl;
			cout<<"Nha xuat ban: "<<NhaXuatBan<<endl;
			cout<<"Ngay thang nam xuat ban: "<<NgayThangNamXuatBan<<endl;
			cout<<"So trang: "<<SoTrang<<endl;
			cout<<"So ban luu thu vien: "<<SoBanLuuThuVien<<endl;
			cout<<"Tac gia: "<<TacGia<<endl;
		}
};
class SachMuon: public Sach{
	private:
		string NgayMuon,NgayHenTra;
	public:
		void DocThongTinSachMuon(ifstream &DocFile){
			Sach::DocThongTinSach(DocFile);
			getline(DocFile, NgayMuon, '#');	
			getline(DocFile, NgayHenTra, '\n');
		}
		void XuatSachMuon(){
			Sach::XuatSach();
			cout<<"Ngay muon: "<<NgayMuon<<endl;
			cout<<"Ngay hen tra: "<<NgayHenTra<<endl;
		}
		string getMaSoSach(){
			return MaSoSach;
		}
};
class SachMuonDoc: public Sach{
	private:
		string GioMuonDoc,GioTra;
	public:
		void DocThongTinSachMuonDoc(ifstream &DocFile){
			Sach::DocThongTinSach(DocFile);
			getline(DocFile, GioMuonDoc, '#');	
			getline(DocFile, GioTra, '\n');
		}
		void XuatSachMuonDoc(){
			Sach::XuatSach();
			cout<<"Gio muon doc: "<<GioMuonDoc<<endl;
			cout<<"Gio tra: "<<GioTra<<endl;
		}
		string getNhaXuatBan(){
			return NhaXuatBan;
		}
};
//Tim kiem Sach Muon
void TimKiemTheoSachMuonTheoMa(SachMuon sm[],int SoSachMuon){
	string MaMuonCanTim;
	int dem=1,i;
	cout<<"Nhap ma sach muon can tim: ";
	fflush(stdin);
	getline(cin,MaMuonCanTim);
	for(i=0;i<SoSachMuon;i++){
		if(sm[i].getMaSoSach()==MaMuonCanTim){
			cout<<"\tSach muon can tim thu "<<dem++<<endl;
			sm[i].XuatSachMuon();
		}
	}
	if(dem==1) cout<<"Khong co sach muon nao co ma "<<MaMuonCanTim<<" can tim\n";
}
//Thong ke Sach Muon Doc
void ThongKeSoSangKienKinhNghiem(SachMuonDoc smd[],int SoSachMuonDoc){
	float s=0;
	int dem=0;
	for(int i=0;i<SoSachMuonDoc;i++){
		if(smd[i].getNhaXuatBan()=="Dai hoc Viet Nam"){
			dem = dem + 1;
		}
	}
	if(dem==0) cout<<"Khong co Sach Muon Doc nao co nha xuat ban la Dai hoc Viet Nam\n";
	else{
		cout<<"Ti le so Sach Muon Doc co nha xuat ban la Dai hoc Viet Nam la: "<<(float)dem/SoSachMuonDoc*100<<" %\n";
	}
}
int main(){
	int SoSachMuon,SoSachMuonDoc,i;
	string z;
	ifstream docfile;
	docfile.open("detai4.txt");
		if(docfile==NULL){
		cout<<"Mo file detai4.txt khong thanh cong. Vui long kiem tra lai duong dan\n";
		return 0;
	}
	//Doc thong tin sach muon
	docfile>>SoSachMuon;
	getline(docfile,z,'\n');
	SachMuon sm[SoSachMuon];
	for(i=0;i<SoSachMuon;i++){
		sm[i].DocThongTinSachMuon(docfile);
	}
	//Doc thong tin sach muon doc
	docfile>>SoSachMuonDoc;
	getline(docfile,z,'\n');
	SachMuonDoc smd[SoSachMuonDoc];
	for(i=0;i<SoSachMuonDoc;i++){
		smd[i].DocThongTinSachMuonDoc(docfile);
	}
	cout<<"==========Danh Sach Cac Sach Duoc Doc Theo File detai4.txt(Sach Muon,Sach Muon Doc)==========\n";
	cout<<"\t----Danh Sach Sach Muon----\n";
	for(i=0;i<SoSachMuon;i++){
		cout<<"\tSach muon thu "<<i+1<<endl;
		sm[i].XuatSachMuon();
	}
	cout<<"\t----Danh Sach Muon Doc----\n";
	for(i=0;i<SoSachMuonDoc;i++){
		cout<<"\tSach muon doc thu "<<i+1<<endl;
		smd[i].XuatSachMuonDoc();
	}
	cout<<"\n=========Thong Ke=========\n";
	ThongKeSoSangKienKinhNghiem(smd,SoSachMuonDoc);
	int dem = 0;
	while(dem<5){
		dem++;
		cout<<"\n=========Tim Kiem=========\n";
		TimKiemTheoSachMuonTheoMa(sm,SoSachMuon);	
	}
	return 0;
}
