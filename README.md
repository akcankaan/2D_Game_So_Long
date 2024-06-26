# 2D_Game_So_Long

<img width="2114" alt="so_long" src="https://github.com/akcankaan/2D_Game_So_Long/assets/63432799/d5ea91e7-76f9-4cb0-9b80-d442fb1d723a">

"So Long" projesi, basit bir 2D oyun geliştirmeyi amaçlar. Oyuncu, haritadaki tüm toplama elemanlarını toplayarak en kısa yoldan çıkışa ulaşmaya çalışır. Oyun, MiniLibX kütüphanesini kullanarak görselleştirilir ve belirli kurallar dahilinde harita dosyalarını okur.

## İçindekiler
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Özellikler](#özellikler)
- [Kurallar](#kurallar)
- [Gereksinimler](#gereksinimler)
- [Katkıda Bulunma](#katkıda-bulunma)
- [Lisans](#lisans)

## Kurulum
Projeyi klonlayarak başlayın:

 ```bash
git clone git@github.com:akcankaan/2D_Game_So_Long.git
cd so_long
```

Makefile kullanarak projeyi derleyin:
 ```bash
make
```

## Kullanım
1. Oyunu çalıştırmak için:
```
./so_long map/map2.ber
```
2. W, A, S, D tuşlarını kullanarak karakterinizi hareket ettirin ve tüm toplanabilir nesneleri toplayarak çıkışa ulaşmaya çalışın.

## Özellikler
- Oyuncu, W, A, S, D tuşları ile dört yönde hareket edebilir.
- Oyuncu duvarlara çarpamaz.
- Oyuncu her hareket ettiğinde, toplam hareket sayısı terminalde görüntülenir.
- Oyun, 2D bir görünümde (top-down veya profil) oynanır.
- ESC tuşuna basarak veya pencere çerçevesindeki çarpı butonuna tıklayarak oyunu kapatabilirsiniz.
- Harita, duvarlar, toplanabilir nesneler ve boş alanlardan oluşur.

## Kurallar
- Harita dosyası .ber uzantılı olmalıdır.
- Harita, şu karakterlerden oluşmalıdır:
- 0 - Boş alan
- 1 - Duvar
- C - Toplanabilir nesne
- E - Çıkış
- P - Oyuncunun başlangıç pozisyonu
- Harita geçerli bir yol içermelidir.
- Harita dikdörtgen olmalıdır ve duvarlarla çevrili olmalıdır.
- Harita, bir çıkış, en az bir toplanabilir nesne ve bir başlangıç pozisyonu içermelidir.

## Gereksinimler
- MiniLibX
- Libft kütüphanesi
- Makefile

## Katkıda Bulunma
Katkıda bulunmak isterseniz, lütfen bir issue oluşturun veya bir pull request gönderin. Her türlü katkı değerlidir!

## Lisans
Bu proje MIT Lisansı ile lisanslanmıştır. Daha fazla bilgi için LICENSE dosyasına bakınız.

