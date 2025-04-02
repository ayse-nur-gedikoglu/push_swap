# 🧩 push_swap

Bu proje, 42 Network kapsamında geliştirilen, algoritma ve veri yapıları üzerine kurulu bir sıralama problemidir.  
Amaç, verilen tam sayıların bir yığında (stack) belirli kurallar çerçevesinde minimum sayıda işlemle sıralanmasıdır.

---

## Proje Hakkında

Kullanıcıdan komut satırı argümanlarıyla alınan sayılar stack A içerisine yerleştirilir.  
Sıralama işlemi yalnızca izin verilen sınırlı sayıda komut kullanılarak yapılır.  
Sıralama işlemi gerçekleştikçe yapılan hamleler standart çıktı üzerinden yazdırılır.

---

## Kullanılabilir Komutlar

**Swap işlemleri**
- `sa`: A yığınının ilk iki elemanını yer değiştirir
- `sb`: B yığınının ilk iki elemanını yer değiştirir
- `ss`: Aynı anda `sa` ve `sb`

**Push işlemleri**
- `pa`: B'den A'ya eleman taşır
- `pb`: A'dan B'ye eleman taşır

**Rotate işlemleri**
- `ra`: A yığınını yukarı kaydırır
- `rb`: B yığınını yukarı kaydırır
- `rr`: Aynı anda `ra` ve `rb`

**Reverse rotate işlemleri**
- `rra`: A yığınını aşağı kaydırır
- `rrb`: B yığınını aşağı kaydırır
- `rrr`: Aynı anda `rra` ve `rrb`

---

## Uygulama Yapısı

- Küçük boyutlu veriler için (2–5 eleman) özel sıralama algoritmaları uygulanmıştır.
- Büyük boyutlu veriler için bit tabanlı radix sort algoritması tercih edilmiştir.
- Yığınlar bağlı liste (linked list) veri yapısı ile temsil edilmiştir.
- Giriş kontrolleri, tekrar eden sayılar, geçersiz karakterler ve `int` sınır aşımı gibi durumlara karşı yapılmaktadır.

---

## Radix Sort Algoritması

Radix sort algoritması, tüm sayıların önceden sıralanarak indekslenmesi prensibiyle çalışır.  
Her eleman, sıralı listedeki yerini temsil eden bir `index` alır. Sıralama işlemi bu index’ler üzerinden yapılır.

Algoritma şu adımlarla işler:

1. Tüm sayılara sıralı bir index atanır.
2. En büyük index değeri alınarak bu değerin binary olarak kaç bit uzunluğunda olduğu hesaplanır.
3. Her bit pozisyonu (en sağdan başlayarak) için:
   - Eğer elemanın ilgili bit değeri 0 ise B yığınına gönderilir (`pb`)
   - Eğer 1 ise A yığınında kalır ve döndürülür (`ra`)
4. B yığınındaki elemanlar her turun sonunda A’ya geri alınır (`pa`)
5. Bu işlem en büyük bit sayısı kadar tekrar eder.

Bu algoritma sabit uzunlukta ve çok sayıda eleman içeren sıralamalar için uygundur ve işlem sayısı açısından oldukça verimlidir.

---

## Örnek Kullanım

```bash
$ ./push_swap 3 2 1
sa
rra
