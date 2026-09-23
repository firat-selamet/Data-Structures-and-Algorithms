#   Soru 1
# C programlama dilinde 10 elemanlı bir tamsayı dizisi tanımlayınız. Kullanıcıdan dizinin 10
# elemanını alınız ve daha sonra bu elemanları ekrana yazdırınız.
# Programın:
# 1. C kodunu yazınız.
# 2. T(n) zaman maliyetini hesaplayınız.
# 3. O(n) zaman karmaşıklığını bulunuz.
# 4. Programın S(n) alan karmaşıklığını bulunuz.
# Not: n, dizideki eleman sayısını ifade etmektedir. 


dizi = []

print("Lutfen 10 adet tam sayi giriniz: ")

for i in range(10):
    sayi = int(input())
    dizi.append(sayi)

print("Girdiginiz sayilar gosteriliyor...")
for  sayi in dizi:
    print(sayi)



#   S(n) = n + 1  Çünkü dizinin boyutu n ve diğer değişkenimizin olan i'nin maaliyeti 1'dir.

#         Big O gösterimi ile S(n) = O(n) olur. Çünkü dizinin boyutu n ve diğer değişkenimizin olan i'nin maaliyeti 1'dir.
#     Bu nedenle O(n) alan karmaşıklığına sahiptir.

#     T(n) = 6n + 7 Tek for döngüsü ile dizinin elemanlarını almak ve yazdırmak için n kez çalışır. Döngünün başında i'ye değer ataması sabit ve 1'dir.
# Döngü kontrolü n+1 kez çalışır. Döngüde i değerinin artması n kez çalışır. Döngüdeki scanf ve printf fonksiyonları n kez çalışır. İlk ve son for döngüsünün
# başında son olarak da 0 değeri döndürdüğümüz işlemlerin de maliyeti 1'dir. Bu nedenle T(n) = 6n + 7 olur.

#     O(n) zaman karmaşıklığına sahiptir. Çünkü T(n) = 6n + 7 fonksiyonunda n'nin katsayısı 6'dır ve diğer terimler sabittir.
# Bu nedenle O(n) zaman karmaşıklığına sahiptir.