/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**					PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:Proje
**				ÖĞRENCİ ADI...............: Burak Ortakuz
**				ÖĞRENCİ NUMARASI.:G191210041
**				DERS GRUBU…………:C
****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <clocale>
#pragma warning(disable: 4996)//ctime fonksiyonun verdiği hatayı gidermek için
#pragma warning(disable: 6031)//rename fonksiyonunun verdiği hatayı gidermek için
using namespace std;

class Okuyucu {
public:
	void kayıt() {
		int üyeNo=0,alabileceğiKitapSayısı;
		string Tc, isim, soyİsim, doğumTarihi, görevi, telefonNo;
		
		ofstream okuyucu("okuyucular.txt", ios::app);
		ifstream okuyucuoku("okuyucular.txt");
			
			while (!okuyucuoku.eof()) {//Üyenumarası değerini bulmaya yarayan tarama işlemi
				okuyucuoku >> Tc >> isim >> soyİsim >> telefonNo >> doğumTarihi >> üyeNo >> görevi>>alabileceğiKitapSayısı;
			}
			üyeNo++;
			alabileceğiKitapSayısı = 7;
		//Soru dizisi
		cout << "Tc kimlik numarası giriniz:"; cin >> Tc;
		cout << "İsim:";  cin >> isim;
		cout << "Soyisim:"; cin >> soyİsim;		
		cout << "Telefon:"; cin >> telefonNo;		
		cout << "Doğum tarihi:"; cin >> doğumTarihi;		
		cout << "Görevi:";cin >> görevi;		
		//Yazma İşlemi
		okuyucu << Tc << " " << isim << " " << soyİsim << " " << telefonNo << " " << doğumTarihi << " " << üyeNo << " " << görevi << " " << alabileceğiKitapSayısı;
		if (!okuyucu.eof()) {
			okuyucu << endl;
		}
		okuyucu.close();
		okuyucuoku.close();
	}
	void güncelleme() {
		int üyeNo, alabileceğiKitapSayısı;
		string TC,Tc, isim,alınanİsim, soyİsim,alınanSoyİsim, doğumTarihi,alınanDoğumTarihi, görevi,alınanGörevi, telefonNo,alınanTelefonNo,seçim;
		//Tc sistemdeki TC girilecek ve alınanlar değiştirilecek olan 
		string eskiad = "okuyucular2.txt", yeniad = "okuyucular.txt";
		bool silme;
		ifstream okuyucuoku("okuyucular.txt");
		cout << "Güncellemek istediğiniz kişinin Tc kimlik numarasını giriniz:";
		cin >> TC;
		ofstream okuyucu2("okuyucular2.txt");
		while (!okuyucuoku.eof()) {//Üyenumarası değerini bulmaya yarayan tarama işlemi
			okuyucuoku >> Tc >> isim >> soyİsim >> telefonNo >> doğumTarihi >> üyeNo >> görevi >> alabileceğiKitapSayısı;
			silme = true;
			
					if (Tc == TC) {											
						silme = false;
						cout << "Yeni Tc kimlik numarası giriniz:";
						cin >> TC;
						okuyucu2 << TC << " ";
						cout << "Yeni İsim:";
						cin >> alınanİsim;
						okuyucu2 << alınanİsim << " ";
						cout << "Yeni soyisim:";
						cin >> alınanSoyİsim;
						okuyucu2 << alınanSoyİsim << " ";
						cout << "Yeni telefon:";
						cin >> alınanTelefonNo;
						okuyucu2 << alınanTelefonNo << " ";
						cout << "Yeni doğum tarihi:";
						cin >> alınanDoğumTarihi;
						okuyucu2 << alınanDoğumTarihi << " ";
						okuyucu2 << üyeNo << " ";
						cout << "Yeni görevi:";
						cin >> görevi;
						okuyucu2 << görevi << " ";
						okuyucu2 << alabileceğiKitapSayısı << endl;
					}
						if (silme){
							okuyucu2 << Tc << " " << isim << " " << soyİsim << " " << telefonNo << " " << doğumTarihi << " " << üyeNo << " " 
							<< görevi << " " << alabileceğiKitapSayısı << endl;
						}
		}
		okuyucuoku.close();
		okuyucu2.close();
		
	}
	void silme() {
		int üyeNo, alabileceğiKitapSayısı;
		string  Tc,TC, isim,  soyİsim,  doğumTarihi,  görevi,  telefonNo;
		bool doğrulama=false,üyeNoAzaltma=false;
		ofstream okuyucu3("okuyucular3.txt");
		ifstream okuyucuoku("okuyucular.txt");
		
		cout << "Silmek istediğiniz kişinin Tc kimlik numarasını giriniz:";
		cin >> TC;
		
		while (!okuyucuoku.eof()) {
			okuyucuoku >> Tc >> isim >> soyİsim >> telefonNo >> doğumTarihi >> üyeNo >> görevi >> alabileceğiKitapSayısı;
				
			if (Tc == TC) {
				
				üyeNoAzaltma = true;
				doğrulama = true;
				continue;
			}

			
			okuyucu3 << Tc << " " << isim << " " << soyİsim << " " << telefonNo << " " << doğumTarihi << " ";
			if (üyeNoAzaltma==true) {
					üyeNo=üyeNo-1;
			}
			okuyucu3 << üyeNo << " " << görevi << " " << alabileceğiKitapSayısı << endl;
			
			
		}
		if (doğrulama == false) {
			cout << "Aradığınız kişi kayıtlı değildir!";
		}
		okuyucu3.close();
		okuyucuoku.close();
		//Okuyucunun kitaplarını döndürme kısmı
		ifstream ödünç("ödünç.txt");
		ofstream ödünç2("ödünç3.txt");

		string ISBN, alınanTarih, verilecekTarih;
		while (!ödünç.eof()) {
			ödünç >> ISBN >> Tc >> alınanTarih >> verilecekTarih;
			if (Tc != TC) {
				ödünç2 << ISBN << " " << Tc << " " << alınanTarih << " " << verilecekTarih << endl;
			}
		}
		ödünç.close();
		ödünç2.close();

	}
};
class Kitap {
public:
	void kitapEkle() {
		ofstream kitap("kitap.txt",ios::app);
		string ISBN,kitapAdı,yazarAdı, yazarSoyAdı,konu,tür;
		int sayfaSayısı;
		cout << "Kitabın barkodunu giriniz:";
		cin >> ISBN;
		cout << "Kitabın adını giriniz: ";
		cin >> kitapAdı;
		cout << "Kitabın yazarının adını ve soyadını giriniz: ";
		cin >> yazarAdı >> yazarSoyAdı;
		cout << "Kitapın konusunu giriniz: ";
		cin >> konu;
		cout << "Kitapın türünü giriniz: ";
		cin >> tür;
		cout << "Kitapın sayfa sayısını giriniz: ";
		cin >> sayfaSayısı;
		
		kitap << endl << ISBN << " " << kitapAdı << " " << yazarAdı << " " << yazarSoyAdı << " " << konu << " " << tür << " " << sayfaSayısı;
	
		kitap.close();
	}
	void kitapListele() {
		string Tc, TC,ISBN,alınanTarih,verilecekTarih;//Ödünç değerleri
		string ISBN2, kitapAdı, yazarAdı, yazarSoyAdı, konu, tür, sayfaSayısı;//Kitabın değerleri
		bool kontrol=false;
		ifstream kitapoku("kitap.txt");
		ifstream ödünçoku("ödünç.txt");
		cout << "Sahip olduğu kitaplara bakılacak kişinin Tc kimlik numarası:";
		cin >> Tc;
		while (!ödünçoku.eof()) {
			ödünçoku >> ISBN >> TC >> alınanTarih >> verilecekTarih;
			if (Tc == TC) {
				while (!kitapoku.eof()) {
					kitapoku >> ISBN2 >> kitapAdı >> yazarAdı >> yazarSoyAdı >> konu >> tür >> sayfaSayısı;
					if (ISBN2 == ISBN) {
						cout << "Sahip olunan kitaplar:" << endl << "Barkodu: " << ISBN2 << "\t" << "Adı: " << kitapAdı << "\t"<< "Yazar: " << yazarAdı << " " << yazarSoyAdı;
						kontrol = true;
					}
				}
			}
		}
		if (kontrol == false) {
			cout << "Kullanıcı henüz kitap ödünç almamıştır.";
		}

	}
	void kitapSil() {
		string ISBN, alınanISBN, kitapAdı, yazarAdı, yazarSoyAdı, konu, tür;
		int sayfaSayısı;
		bool kontrol = false;
		ifstream kitapOku("kitap.txt");
		ofstream kitapYaz("kitap2.txt");
		cout << "Silinecek kitabın barkod numarasını giriniz:";
		cin >> alınanISBN;
		while (!kitapOku.eof()) {
			kitapOku >> ISBN >> kitapAdı >> yazarAdı >> yazarSoyAdı >> konu >> tür >> sayfaSayısı;
			if (ISBN != alınanISBN) {
				kitapYaz << ISBN << " " << kitapAdı << " " << yazarAdı << " " << yazarSoyAdı << " " << konu << " " << tür << " " << sayfaSayısı;
				kontrol = true;
				if (!kitapOku.eof()) {//Alt satıra geçtiği için oluşan hatanın düzeltimi 
					kitapYaz << endl;
				}
			}
		}
		if (kontrol == false) {
			cout << "Bu barkodda kitap kayıtlı değildir!";
		}
		kitapOku.close();
		kitapYaz.close();
	}
	void kitapGüncelle() {
		string ISBN, alınanISBN, kitapAdı, yazarAdı, yazarSoyAdı, konu, tür;
		int sayfaSayısı;
		bool kontrol=false;
		ifstream kitapOku("kitap.txt");
		ofstream kitapYaz("kitap3.txt");
		cout << "Bilgileri değiştirilecek kitabın barkodunu giriniz:";
		cin >> alınanISBN;
		while (!kitapOku.eof()) {
			kitapOku >> ISBN >> kitapAdı >> yazarAdı >> yazarSoyAdı >> konu >> tür >> sayfaSayısı;
			if (ISBN == alınanISBN) {
				kontrol = true;
				cout << "Kitabın adı:"; cin >> kitapAdı;
				cout << "Kitabın yazarının adı ve soyadı:"; cin >> yazarAdı >> yazarSoyAdı;
				cout << "Kitabun konusu:"; cin >> konu;
				cout << "Kitabun türü:"; cin >> tür;
				cout << "Kitabın sayfa sayısı:"; cin >> sayfaSayısı;
			}
			kitapYaz << ISBN << " " << kitapAdı << " " << yazarAdı << " " << yazarSoyAdı << " " << konu << " " << tür << " " << sayfaSayısı;
			if (!kitapOku.eof()) {//Alt satıra geçtiği için oluşan hatanın düzeltimi 
				kitapYaz << endl;
			}
		}
		if (kontrol == false) {
			cout << "Öyle bir kitap elimizde yoktur.";
		}
		kitapOku.close();
		kitapYaz.close();

	}
};
class Ödünç {
public:
	void ödünçAl() {
		string ISBN, alınanISBN, Tc, geriAlınacakTarih;
		int üyeNo, alabileceğiKitapSayısı;
		string TC, isim, soyİsim, doğumTarihi, görevi, telefonNo;
		bool kontrol = false, kontrol2 = false;
		
		ofstream okuyucuyaz("okuyucular4.txt");
		ifstream okuyucuoku("okuyucular.txt");
		ifstream kitap("kitap.txt");
		ofstream ödünç("ödünç.txt", ios::app);

		cout << "Alınacak kitabın barkodu:";
		cin >> ISBN;
		
		while (!kitap.eof()) {//Alınmak istenen kitap elimizde var mı kontrol ediyor 
			kitap >> alınanISBN;
			kitap.ignore();
			
			
			if (alınanISBN == ISBN) {
				kontrol = true;

			}

		}
		if (kontrol == false) {
			cout<< "Öyle bir kitap elimizde bulunmamaktadır.";
			return ;
		}
		else {
			cout << "Kitabı alacak kişinin Tc kimlik numarası:";
			cin >> Tc;
			while (!okuyucuoku.eof()) {
				okuyucuoku >> TC >> isim >> soyİsim >> telefonNo >> doğumTarihi >> üyeNo >> görevi >> alabileceğiKitapSayısı;
				
				if (Tc == TC) {
					kontrol2 = true;
					okuyucuyaz << TC;
				}
			}
			
			if (kontrol2 == true) {
				cout << "Kitabın teslim edileceği tarih:";
				cin >> geriAlınacakTarih;

				ödünç << ISBN << " ";
				ödünç << Tc << " ";
				time_t now = time(0);
				struct tm zaman;
				zaman = *localtime(&now);
				ödünç << zaman.tm_mday << ":" << zaman.tm_mon + 1 << ":" << zaman.tm_year + 1900 << " ";
				ödünç << geriAlınacakTarih << endl;
			}
			else {
				cout << "Böyle bir okuyucu bulunmamaktadır.";
			}
		}
		okuyucuoku.close();
		ödünç.close();
		kitap.close();
	}
	void teslimEt() {
		string ISBN,okunanISBN,boşDeğer,yazılacakISBN,Tc,alınanTarih,verilecekTarih;
		bool kontrol = false;
		
		ofstream ödünç2("ödünç2.txt");
		ifstream ödünç("ödünç.txt");

		cout << "Teslim edilecek kitabın barkod numarası:";
		cin >> ISBN;
		while (!ödünç.eof()) {
			ödünç >> okunanISBN>>Tc>>alınanTarih>>verilecekTarih;
		
			if (okunanISBN != ISBN) {
				kontrol = true;
				ödünç2 << okunanISBN << " " << Tc << " " << alınanTarih << " " << verilecekTarih << endl;
			}
		}
		if (kontrol == false) {
			cout << "Hatalı barkod numarası!";
		}
			
	
	
	}
};






int main()
{
	setlocale(LC_ALL, "Turkish");//Türkçe dil desteği 
	//Classların getirilmesi
	Okuyucu okuyucu;
	Kitap kitap;
	Ödünç ödünç;
	//Kullanıcı için değerler
	int seçim;
	string kullanıcıAdı,şifre; 
	string girilenKullanıcıAdı, girilenŞifre;
	bool kontrol = true,durdurma=true;
	
	ifstream kullanıcı("kullanıcılar.txt");
	
	while(kontrol==true){//Kullanıcı adı veya şifrenin hatalı olma durumunda tekrar sorma döngüsü
		
		cout << "Kullanıcı Adı:";
		cin >> girilenKullanıcıAdı;
		cout << "Şifre:";
		cin >> girilenŞifre;
		kullanıcı.seekg(0);//Dosyada 1. satıra gidiyor 
		while (!kullanıcı.eof()) {//Dosyayı tarıyor
			getline(kullanıcı, kullanıcıAdı);
			getline(kullanıcı, şifre);
				if (kullanıcıAdı == girilenKullanıcıAdı && şifre == girilenŞifre) {
					cout << "Hoşgeldiniz! İşlem için numarayı giriniz!"<< endl ;
					kontrol = false;
					break;
				}
				
		}
		if (kullanıcıAdı != girilenKullanıcıAdı || şifre != girilenŞifre) {
			cout << "Kullanıcı adı veya şifre hatalı!" << endl;
		}
	}
	kullanıcı.close();
	while (durdurma==true) {//Seçeneklerin tekrar ekrane gelmesi için gerekli döngü
		cout << "1-Okuyucu kaydı\n2-Okuyucu kaydı güncelleme\n3-Okuyucu silme\n4-Okuyucunun sahip olduğu kitaplar\n5-Okuyucu kitap ödünç alma\n" <<
			"6-Ödünç kitap iade etme\n7-Kitap ekleme\n8-Kitap silme\n9-Kitap düzenleme\n0-Çıkış\n";
		cin >> seçim;
		switch (seçim) {//Seçime bağlı yapılacak olaylar
			case 1:
				okuyucu.kayıt();
				cout << endl << endl << "İşlem için numarayı giriniz!" << endl;
				break;
			case 2:
				okuyucu.güncelleme();
				remove("okuyucular.txt");
				rename("okuyucular2.txt", "okuyucular.txt");
				cout << endl << endl << "İşlem için numarayı giriniz!" << endl;
				break;
			case 3:
				okuyucu.silme();
				remove("okuyucular.txt");
				rename("okuyucular3.txt", "okuyucular.txt");
				remove("ödünç.txt");
				rename("ödünç3.txt", "ödünç.txt");
				cout << endl << endl << "İşlem için numarayı giriniz!" << endl;
				break;
			case 4:
				kitap.kitapListele();
				cout << endl << endl << "İşlem için numarayı giriniz!" << endl;
				break;
			case 5:
				ödünç.ödünçAl();
				cout << endl << endl << "İşlem için numarayı giriniz!" << endl;
				break;
			case 6:
				ödünç.teslimEt();
				remove("ödünç.txt");
				rename("ödünç2.txt", "ödünç.txt");
				cout << endl << endl << "İşlem için numarayı giriniz!" << endl;
				break;
			case 7:
				kitap.kitapEkle();
				cout << endl << endl << "İşlem için numarayı giriniz!" << endl;
				break;
			case 8:
				kitap.kitapSil();
				remove("kitap.txt");
				rename("kitap2.txt", "kitap.txt");
				cout << endl << endl << "İşlem için numarayı giriniz!" << endl;
			case 9:
				kitap.kitapGüncelle();
				remove("kitap.txt");
				rename("kitap3.txt", "kitap.txt");
				cout << endl << endl << "İşlem için numarayı giriniz!" << endl;
				break;
			case 0:
				durdurma = true;
				return 0;
				
		}
	}
}