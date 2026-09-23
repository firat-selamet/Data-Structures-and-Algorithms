#   Soru 2:
# Kullanıcıdan bir tam sayı alın ve bu sayının bir Palindrom Sayı olup olmadığını bulan C
# programını yazın.

kalan = 0
ters = 0

print("Lutfen bir sayi giriniz: ")
sayi = int(input())

test = sayi

while (sayi > 0):
    kalan = sayi % 10
    ters = ters * 10 + kalan
    sayi //= 10
    
if test == ters:
    print("Girdiginiz sayi palindromdur.")
else :
    print("Girdiginiz sayi palindrom degildir.")

#  S(n) = Toplam 4 değişkenimiz olduğundan maliyetimiz 4'tür.

#         Big O gösterimi ile S(n) = O(1) olur. Çünkü toplam 4 değişkenimiz olduğundan maliyetimiz 4'tür.
#     Bu nedenle O(1) alan karmaşıklığına sahiptir.

#     T(n) = İki tane değişkene tanımlandığı anda değer verildi iki diğer değişkene tanımlandıktan sonra değer verildi burada maliyet 4'tür.
# While döngüsünden hemen önce iki tane fonksiyon çalıştırıldı burada maliyet 2'dir. While döngüsü girilen sayının basamak sayısı kadar çalıştığından
# her döngüde log 10 tabanı çarpımı tane işlem yapılır, burada maliyet 3log₁₀(n) olur.While döngüsündeki döngü kontrolü n+1 kez çalışır ve maliyeti log₁₀(n)+1'dir.
# While döngüsünden sonra if else kontrolü yapılır ve maliyeti 1'dir ve koşulların herhangi birinin içine girildiği takdirde çalışacak bir adet fonksiyon daha
# mevcuttur ve maliyeti 1'dir. Son olarak 0 değeri döndürdüğümüz işlemin de maliyeti 1'dir. Bu nedenle T(n) = 4log₁₀(n) + 10 olur.

#     O(log n) zaman karmaşıklığına sahiptir. Çünkü T(n) = 4log₁₀(n) + 10 fonksiyonunda log₁₀(n)'nin katsayısı 4'dir ve diğer terimler sabittir.
# Bu nedenle O(log n) zaman karmaşıklığına sahiptir.
# 
