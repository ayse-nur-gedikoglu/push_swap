# 🧩 push_swap

**push_swap**, 42 Network’teki algoritma odaklı projelerden biridir.  
Amaç, verilen sayıları sadece belirli kurallar çerçevesinde sıralayarak, sonucu minimum işlemle elde etmektir.  
Kodunuzu değerlendiren sistem, yalnızca yaptığı işlemleri (komutları) okur — bu da projeyi algoritmik düşünme ve optimizasyon açısından çok değerli hale getirir.

---

## 🚀 Proje Amacı

- Komut satırından verilen `int` tipindeki sayıları stack A'ya yerleştir
- Yalnızca belirli işlemlerle bu stack'i sıralı hale getir
- Stack B'yi yardımcı yığın olarak kullanabilirsin
- Ekrana yalnızca uyguladığın sıralama komutlarını yaz (örneğin: `sa`, `pb`, `ra`...)

---

## ⚙️ Kullanılabilir Komutlar

### 📥 Push
- `pa` → B'den A'ya eleman taşı
- `pb` → A'dan B'ye eleman taşı

### 🔁 Swap
- `sa` → A’daki ilk iki elemanı yer değiştir
- `sb` → B’deki ilk iki elemanı yer değiştir
- `ss` → Aynı anda `sa` ve `sb`

### 🔄 Rotate
- `ra` → A’yı yukarı kaydır (ilk eleman sona gider)
- `rb` → B’yi yukarı kaydır
- `rr` → `ra` ve `rb` birlikte

### ↩️ Reverse Rotate
- `rra` → A’yı aşağı kaydır (son eleman başa gelir)
- `rrb` → B’yi aşağı kaydır
- `rrr` → `rra` ve `rrb` birlikte

---

## 🧠 Öğrenilen Temel Konular

### ✔️ Bağlı Listeler (Linked Lists)
- Stack yapısı bağlı liste ile temsil edilir
- Eleman ekleme, silme, yer değiştirme gibi işlemler manuel olarak yazılır

### ✔️ Bit Düzeyinde Operasyonlar (Bitwise)
- Radix algoritması için binary mantığıyla bitler üzerinden sıralama yapılır
- `>>`, `&` gibi bit işlemleri ile bit bazlı kontrol sağlanır

### ✔️ Hata Yönetimi
- Kullanıcının girdiği değerlerde: boşluklar, tekrar eden sayılar, sayısal olmayan karakterler, `int` sınır aşımı gibi durumlar tespit edilip engellenir

### ✔️ Algoritma Optimizasyonu
- Küçük stack’ler için özel hardcoded sıralamalar
- Büyük stack’ler için genel algoritmalar
- Mümkün olan en az işlemle sıralama hedeflenir

---

## 🧮 Radix Sort Algoritması Nasıl Çalışır?

1. Tüm sayılar sıralanarak her elemana **index** atanır (0'dan başlayarak).
2. En büyük index’e bakılarak bu sayıların kaç bitlik olduğu hesaplanır (`get_max_bits`).
3. Her bit pozisyonu (LSB'den MSB’ye) için:
   - **Bit 0 olanlar B’ye gönderilir**
   - **Bit 1 olanlar A’da tutulur (`ra` ile döndürülür)**
4. Her bit turu sonunda B'deki elemanlar A’ya geri alınır (`pa`)
5. Bu işlem `max_bits` kadar tekrarlanır
6. Sonuç olarak sayılar sıralanmış olur

### 🔢 Örnek (index bazlı):

| index | binary |
|-------|--------|
| 0     | 000    |
| 1     | 001    |
| 2     | 010    |
| 3     | 011    |
| 4     | 100    |

- 0. bit → `pb`: 0, 2, 4 / `ra`: 1, 3  
- 1. bit → `pb`/`ra` ayrımı tekrar  
- 2. bit → son ayrım ve sıralama tamamlanır

Bu algoritma `O(n * log n)` karmaşıklığıyla büyük veri kümelerinde oldukça etkilidir.

---

## 💻 Projeyi Çalıştırmak

```bash
make
./push_swap 4 2 1 3 5
