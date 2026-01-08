# Algoritmalar ve Programlama Dönem Projesi

Bu repository, Algoritmalar ve Programlama dersi kapsamında hazırlanan dönem projesini içermektedir. Proje, C programlama dili kullanılarak geliştirilmiş olup gezegenlerin yerçekimi ivmelerine bağlı olarak çeşitli fizik deneylerinin simülasyonunu yapmaktadır.

## Projenin Amacı

Bu projenin amacı:
- C programlama dilinde algoritma kurma becerisini geliştirmek
- Dizi ve pointer kullanımını pekiştirmek
- Fonksiyonlara parametre gönderme mantığını kavramak
- Fiziksel formüllerin yazılım ortamında uygulanmasını göstermektir
- 
## Proje Özellikleri

- Menü tabanlı konsol uygulaması
- Gezegenlerin yerçekimi ivmeleri dizi içerisinde tutulmuştur
- Diziler fonksiyonlara pointer olarak gönderilmiştir
- Dizi elemanlarına `*(g + i)` yöntemiyle erişilmiştir
- Negatif girişler ternary operatör ile kontrol edilmiştir
- Toplam 9 adet fizik deneyi bulunmaktadır
  

## Gerçekleştirilen Deneyler

- Serbest Düşme Deneyi: Süreye bağlı kat edilen yol hesabı .
- Yukarı Atış Deneyi: Maksimum çıkış yüksekliği hesabı .
- Ağırlık Deneyi: Kütleye bağlı ağırlık hesabı .
- Kütleçekimsel Potansiyel Enerji Deneyi: Konum enerjisi hesabı .
- Hidrostatik Basınç Deneyi: Sıvı derinliğine bağlı basınç hesabı .
- Arşimet Kaldırma Kuvveti Deneyi: Batan hacme bağlı kuvvet hesabı .
- Basit Sarkaç Periyodu Deneyi: İp uzunluğuna bağlı salınım süresi hesabı .
- Sabit İp Gerilmesi Deneyi: Düşey doğrultuda ip gerilmesi hesabı .
- Asansör Deneyi: İvmeli hareket durumunda etkin ağırlık hesabı .

## Kullanılan Gezegenler

- Merkür  
- Venüs  
- Dünya  
- Mars  
- Jüpiter  
- Satürn  
- Uranüs  
- Neptün  

Yerçekimi ivmeleri NASA tarafından yayımlanan ortalama yüzey yerçekimi değerlerinden alınmıştır.


## Teknik Zorunluluklar ve Uygulama

 *Proje geliştirilirken aşağıdaki akademik kurallara titizlikle uyulmuştur* :
- Pointer Aritmetiği: Gezegenlerin yerçekimi ivmeleri bir dizi içinde tutulmakta ve bu dizinin elemanlarına erişim tamamen pointer mantığıyla (*(ptr + i)) yapılmaktadır .
- Ternary Operator: Negatif girilen kütle, süre, hacim veya uzunluk değerleri if blokları yerine ternary operator kullanılarak mutlak değerine dönüştürülmektedir.
- Modüler Fonksiyonlar: Tüm deneyler parametre olarak pointer alan bağımsız fonksiyonlarda hesaplanmaktadır.
- Girdi Yönetimi: Kullanıcı deney seçim ekranında -1 değerini girene kadar program çalışmaya devam eder .
- 

## Birimler ve Metrikler
- Simülasyonda anlamlı sonuçlar elde etmek için standart birim sistemleri (kg, m, s, J, N) kullanılmıştır .

##  Kullanılan Teknolojiler

- C Programlama Dili
- Standart C kütüphaneleri
  - `stdio.h`
  - `math.h`

