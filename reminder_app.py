from tkinter import *
from tkcalendar import DateEntry
import ssl
import smtplib

master = Tk()

master.title("Hatırlatma Uygulaması")

# Açılacak pencerenin büyüklüğünü ayarlıyoruz.
canvas = Canvas(master, height=450, width=750)
canvas.pack()

# Açılan pencere üzerinde menüler oluşturmak için frame açıyoruz ve daha sonra hangi renk ve nereler olacağınının koordinatlarını giriyoruz.
# Başlık için.
frame_baslik = Frame(master, bg='khaki')
frame_baslik.place(relx=0.1, rely=0.01, relwidth=0.8, relheight=0.08)
# Üst menü için.
frame_ust = Frame(master, bg='light blue')
frame_ust.place(relx=0.1, rely=0.1, relwidth=0.8, relheight=0.1)
# Sol alttaki menü için.
frame_alt_sol = Frame(master, bg='light blue')
frame_alt_sol.place(relx=0.1, rely=0.21, relwidth=0.23, relheight=0.5)
# Sağ alttaki menü için.
frame_alt_sag = Frame(master, bg='light blue')
frame_alt_sag.place(relx=0.34, rely=0.21, relwidth=0.56, relheight=0.5)

############## Part I ##############
############## Frame Başlık ##############
baslik = Label(frame_baslik, bg='khaki', text="Hatırlatma Uygulamasına Hoş Geldiniz!", font="Verdana 10 bold")
baslik.pack(padx=10, pady=10)

############## Frame üst ##############

hatirlatma_tipi_etiket = Label(frame_ust, bg='light blue', text="Hatırlatma Tipi:", font="Verdana 12 bold")       # Yazının fontu, büyüklüğü hakkında işlem yapmak istiyorsak Label içinde.
hatirlatma_tipi_etiket.pack(padx=10, pady=10, side=LEFT)                                                          # Yazının konumu için işlem yapmak istiyorsak .pack içinde.

# Açılır pencerenin açılmadan önce boş olmasını ayarlıyoruz.
hatirlatma_tipi_opsiyon = StringVar(frame_ust)
hatirlatma_tipi_opsiyon.set("Lütfen birini seçiniz.")

# Açılır pencerenin yerini ve seçeneklerini ayarlıyoruz.
hatirlatma_tipi_acilir_menu = OptionMenu(frame_ust, hatirlatma_tipi_opsiyon, "Doğum Günü", "Alışveriş", "Ödeme")
hatirlatma_tipi_acilir_menu.pack(padx=10, pady=10, side=LEFT)

hatirlatma_tarihi_etiket = Label(frame_ust, bg='light blue', text="Hatırlatma Tarihi:", font="Verdana 12 bold")
hatirlatma_tarihi_etiket.pack(padx=10, pady=10, side=LEFT)

# Tarih seçerken açılacak pencerenin yazı tipini, rengini, dilini ayarladık.
hatirlatma_tarih_secici = DateEntry(frame_ust, width= 12, background='orange', foreground='black', borderwidth=1, locale="tr_TR")
hatirlatma_tarih_secici._top_cal.overrideredirect(True)
hatirlatma_tarih_secici.pack(padx=10, pady=10, side=RIGHT)


############## Part II ##############
############## Frame alt sol ##############

Label(frame_alt_sol, text="Hatırlatma Yöntemi:", bg='light blue', font="Verdana 10 bold").pack(padx=10, pady=10, anchor=NW)

var = IntVar()
# 1. ya da 2. kutucuktan birini seçmek için radiobutton kullanıldı. Yani 2'si de aynı anda seçilemiyor.
# 1. seçenek için.
RB1= Radiobutton(frame_alt_sol, text="Sisteme Kaydet", variable=var, value=1, bg='light blue', font="Verdana 10")
RB1.pack(anchor=NW, pady=5, padx=15)
# 2. seçenek için.
RB2= Radiobutton(frame_alt_sol, text="E-posta Gönder", variable=var, value=2, bg='light blue', font="Verdana 10")
RB2.pack(anchor=NW, pady=5, padx=15)

# Bu butonlar birbirlerine bağlı olmadıkları için hepsine ayrı ayrı değer verdik.
# 1. buton için.
var1 = IntVar()
CB1 = Checkbutton(frame_alt_sol, text="Bir hafta önce", variable=var1, onvalue=1, offvalue=0, bg='light blue', font="Verdana 10")
CB1.pack(anchor=NW, pady=2, padx=25)
# 2. buton için.
var2 = IntVar()
CB2 = Checkbutton(frame_alt_sol, text="Bir gün önce", variable=var2, onvalue=1, offvalue=0, bg='light blue', font="Verdana 10")
CB2.pack(anchor=NW, pady=2, padx=25)
# 3. buton için.
var3 = IntVar()
CB3 = Checkbutton(frame_alt_sol, text="Aynı gün", variable=var3, onvalue=1, offvalue=0, bg='light blue', font="Verdana 10")
CB3.pack(anchor=NW, pady=2, padx=25)


############## Part III ##############
############## Frame alt sağ ##############
from tkinter import messagebox

def gonder():
    son_mesaj = ""
    try:
        if var.get():
            if var.get() == 1:
                # Sisteme kaydet butonunu seçtikten sonra yazılan mesaj varsa onu hatirlatmalar.txt dosyasına yazıyor.
                son_mesaj += "Mesajınız başarıyla sisteme kaydedilmiştir."

                tip = hatirlatma_tipi_opsiyon.get() if hatirlatma_tipi_opsiyon.get() == '' else "Genel"
                tarih = hatirlatma_tarih_secici.get()
                mesaj = metin_alani.get("1.0", END)


                with open("hatirlatmalar.txt", "w") as dosya:
                    dosya.write('{} kategorisinde, {} tarihine, {}notuyla hatirlatma.'.format(tip, tarih, mesaj))
                    dosya.close()

            elif var.get() == 2:
                kullanici = ''
                sifre = ''
                alici = kullanici
               # baslik = 'Python gönderisi'
                mesaj = 'Deneme mesajı'
                context = ssl.create_default_context()
                port = 465
                host = "smtp.gmail.com"

                eposta_sunucusu = smtplib.SMTP_SSL(host= host, port= port, context=context)
                eposta_sunucusu.login(kullanici, sifre)
                eposta_sunucusu.sendmail(kullanici, alici, mesaj)
                son_mesaj += "Mesajınız e-posta yoluyla gönderilmiştir."

            messagebox.showinfo("Başarılı İşlem.", son_mesaj)

        else:
            # Gönderilmek için mesaj yazmadığımızda bu hatayı veriyor.
            son_mesaj += "Gerekli alanın doldurulduğundan emin olunuz!"
            messagebox.showwarning("Yetersiz Bilgi", son_mesaj)

    except:
        # Herhangi bir sebepten dolayı gönderilemediğinde bu hatayı veriyor.
        son_mesaj += "İşlem başarısız oldu!"
        messagebox.showerror("Başarısız işlem", son_mesaj)
    finally:
        # Bütün işlemleri yaptıktan sonra ve gönder butonuna bastıktan sonra uygulamayı kapatıyor.
        master.destroy()

Label(frame_alt_sag, text="Hatırlatma Mesajı:", bg='light blue', font="Verdana 10 bold").pack(padx=10, pady=10, anchor=NW)
# Yazı yazılabilecek bir alan oluşturuyoruz.
metin_alani = Text(frame_alt_sag, height=9, width=50)
metin_alani.tag_configure('style', foreground='#bfbfbf', font='Verdana 7 bold')
metin_alani.pack()
# Gönder butonu ekledik ve gönder fonksiyonu yazmamız gerekiyor.
gonder_butonu = Button(frame_alt_sag, text="Gönder", command=gonder)
gonder_butonu.pack(anchor=S)




master.mainloop()

