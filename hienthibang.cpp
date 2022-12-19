int menu(str thaotac[8], int n) {
	List<KhachHang> khach;
	List<Xe> xe;
	List<DonHang> donhang;
	List<DonDatHang> dondathang;
	List<TraGop> tragop;
	List<LaiSuat> laisuat;
	List<LichHen> lichhen;
	List<NhanVien> nhanvien;
	List<ChucVu> chucvu;
	int mn = 1;
	int tt = 0;
	int* mau = new int[n];
	for (int i = 1; i <= n; i++) {
		mau[i - 1] = MAUCHU;
		mau[0] = MAUNEN;
	}
	do {
		clrscr();
		for (int i = 0; i < n; i++) {
			TextColor(mau[i]);
			cout << "\t\t\t\t\t\t\t" << i + 1 << "." << thaotac[i] << endl;
		}
		char c = _getch();
		if ((int)c == -32) c = _getch();
		switch ((int)c) {
		case 72:
			if (tt == 0) {
				mn = 1;
			}
			else {
				tt--;
				mn--;
			}
			break;
		case 80:
			if (tt == n - 1) {
				mn = 8;
			}
			else {
				tt++;
				mn++;
			}
			break;
		case 13:
			cout << endl << endl;
			do {
			switch (mn) {
			case 1:
				cout << "\t\t\t\t\t\t\t\tDANH SACH THONG TIN KHACH HANG" << endl << endl;
				Table_Front_1_Khach_Hang();
				cout << char(179);
				cout << "  Ma so khach hang  |    Ten khach hang        |      Gioi tinh     |       Ngay sinh      |       Dia chi          |         CCCD         |    So dien thoai    |" << endl;
				Table_Front_2_Khach_Hang();
				khach.input("KhachHang.txt");
				khach.display();
				Table_Back_Khach_Hang();
				khach.Giai_phong_vung_nho();
				cout << endl;
				system("pause");
				goto again;
			case 2:
				cout << "\t\t\t\t\tDANH SACH THONG TIN CAC LOAI XE CO TRONG SHOWROOM" << endl << endl;
				Table_Front_1_Xe();
				cout << "|      Ma so xe      |        Hang xe       |         Ten xe         |      Mau sac     |    So luong   |    Gia thanh (VND)   |" << endl;
				Table_Front_2_Xe();
				xe.input("Xe.txt");
				xe.display();
				Table_Back_Xe();
				xe.Giai_phong_vung_nho();
				cout << endl;
				system("pause");
				goto again;
			case 3:
				dondathang.input("DonDatHang.txt");
				xe.input("Xe.txt");
				dondathang.Don_dat_hang(dondathang, xe);
				//menu_don_dat_hang(don_dat_hang, 3);
				dondathang.Giai_phong_vung_nho();
				xe.Giai_phong_vung_nho();
				system("pause");
				goto again;
			case 4:
				nhanvien.input("NhanVien.txt");
				chucvu.input("ChucVu.txt");
				nhanvien.Danh_sach_nhan_vien(nhanvien, chucvu);
				nhanvien.Giai_phong_vung_nho();
				chucvu.Giai_phong_vung_nho();
				system("pause");
				goto again;
			case 5:
				menu_doanh_thu(doanhthu, 4);
				goto again;
			case 6: 

				system("pause");
				goto again;
			case 7:
				cout << "\t\t\t\t\t\tDANH SACH THONG TIN KHACH HANG MUA TRA GOP VA TIEN LAI CAN TRA HANG THANG" << endl << endl;
				Table_Front_1_TraGop();
				cout << "| Ma so khach hang |      Ten khach hang     |      Ten ngan hang     |    Thoi gian tra gop    | Lai suat vay  |    Thoi han vay ( nam )   |       Du no goc       |     So tien tra truoc     |    Tien goc hang thang   |    Tien lai hang thang   |   Tong tien phai tra hang thang    |" << endl;
				Table_Front_2_TraGop();
				tragop.input("TraGop.txt");
				laisuat.input("LaiSuatNH.txt");
				khach.input("KhachHang.txt");
				xe.input("Xe.txt");
				donhang.Chinh_sach_tra_gop(khach, xe, tragop, laisuat);
				Table_Back_TraGop();
				donhang.Giai_phong_vung_nho();
				laisuat.Giai_phong_vung_nho();
				khach.Giai_phong_vung_nho();
				tragop.Giai_phong_vung_nho();
				xe.Giai_phong_vung_nho();
				cout << endl;
				system("pause");
				goto again;
			case 8:
				cout << "Ket thuc chuong trinh" << endl;
				exit(1);
			default:
				break;
			}
			} while (mn != 8);
		}
		again:
		for (int i = 0; i < n; i++)
			mau[i] = MAUCHU;
		mau[tt] = MAUNEN;
	} while (1);
}
