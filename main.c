#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <assert.h> 

# define STRLEN(a)          printf("'%s' = %zu (%zu)\n", a, ft_strlen(a), strlen(a));
# define STRCMP(d, e)      printf("`%s`:`%s` = %d (%d)\n", (d ? d : "(null)"), (e ? e : "(null)"), ft_strcmp(d, e), strcmp(d, e));

extern size_t ft_strlen(const char *str);
extern int ft_strcmp(char const *s1, const char *s2);
extern char *ft_strcpy(char *dst, char const *src);
extern ssize_t ft_write(int fd, const void *buf, size_t nbyte);
extern ssize_t ft_read(int fd, void *buf, size_t nbyte);
extern char *ft_strdup(char const *s1);

void strdup_test(const char *input) {
    char *dup_std = strdup(input);
    char *dup_ft  = ft_strdup(input);

    printf("Input        : \"%s\"\n", input);
    printf("strdup       : \"%s\"\n", dup_std);
    printf("ft_strdup    : \"%s\"\n", dup_ft);

    if (dup_std && dup_ft) {
        if (strcmp(dup_std, dup_ft) == 0) {
            printf("Strings match\n");
        } else {
            printf("Strings do not match\n");
        }

        if (dup_std != dup_ft) {
            printf("Pointers are different (deep copy)\n");
        } else {
            printf("Pointers are the same (shallow copy)\n");
        }
    } else {
        printf("One of the strdup functions returned NULL\n");
    }

    free(dup_std);
    free(dup_ft);
    printf("---------------------------------------------------\n");
}

int main()
{
    int     i = 0;
    long    r = 0;
    char    buffer[100];
    ssize_t ret;
    char    *aux;
    char    *aux2;

    while (i < 100)
    {
        buffer[i] = 0;
        i++;
    }

    printf("Test: ==> ft_strlen\n");

    STRLEN("");
    printf("---------------------------------------------------\n");
    STRLEN("abcd");
    printf("---------------------------------------------------\n");
    STRLEN("ABCDEFG");
    printf("---------------------------------------------------\n");
    STRLEN("0123456789abcdef");
    printf("---------------------------------------------------\n");
    STRLEN("42");
    printf("---------------------------------------------------\n");
    STRLEN("1");
    printf("---------------------------------------------------\n");
    printf("\nTest: ==> ft_strcmp\n");
    printf("---------------------------------------------------\n");

    STRCMP("", "");
    printf("---------------------------------------------------\n");
    STRCMP("abcd", "abcd");
    printf("---------------------------------------------------\n");
    STRCMP("abcd", "abce");
    printf("---------------------------------------------------\n");
    STRCMP("abcd", "abcefgh");
    printf("---------------------------------------------------\n");
    STRCMP("", "abcd");
    printf("---------------------------------------------------\n");
    STRCMP("abcd", "");
    printf("---------------------------------------------------\n");

    printf("\nTest: ==> ft_strcpy\n");
    printf("`%s` (`abcd`)\n", ft_strcpy(buffer, "abcd"));
    printf("---------------------------------------------------\n");
	printf("`%s` (empty)\n", ft_strcpy(buffer, ""));
    printf("---------------------------------------------------\n");
	printf("`%s` (`long message`)\n", ft_strcpy(buffer, "long message"));
    printf("---------------------------------------------------\n");

    printf("\nTest: ==> ft_write\n");
    ft_write(1, "Mio: hi\n", 9); 
    write(1, "Original: hi\n", 14);
    printf("---------------------------------------------------\n");
    ft_write(1, "Mio: 𓄿 𓅀 𓅁 𓅂 𓅃 𓅄 𓅅 𓅆 𓅇 𓅈 𓅉 𓅊 𓅋 𓅌 𓅍 𓅎 𓅏 𓅐 𓅑 𓅒 𓅓 𓅔 𓅕 𓅖 𓅗 𓅘 𓅙 𓅚 𓅛 𓅜 𓅝 𓅞 𓅟 𓅠 𓅡 𓅢 𓅣 𓅤 𓅥 𓅦 𓅧 𓅨 𓅩 𓅪 𓅫 𓅬 𓅭 𓅮 𓅯 𓅰 𓅱 𓅲 𓅳 𓅴 𓅵 𓅶 𓅷 𓅸 𓅹 𓅺 𓅻 𓅼 𓅽 𓅾 𓅿 𓆀 𓆁 𓆂 𓆃 𓆄 𓆅 𓆆 𓆇 𓆈 𓆉 𓆊 𓆋 𓆌 𓆍 𓆎 𓆏 𓆐 𓆑 𓆒 𓆓 𓆔 𓆕 𓆖 𓆗 𓆘 𓆙 𓆚 𓆛 𓆜 𓆝 𓆞 𓆟 𓆠 𓆡 𓆢 𓆣 𓆤 𓆥 𓆦 𓆧 𓆨𓆲𓃒 𓃓 𓃔 𓃕 𓃖 𓃗 𓃘 𓃙 𓃚 𓃛 𓃜 𓃝 𓃞 𓃟 𓃠 𓃡 𓃢 𓃣 𓃤 𓃥 𓃦 𓃧 𓃨 𓃩 𓃪 𓃫 𓃬 𓃭 𓃮 𓃯 𓃰 𓃱 𓃲 𓃳 𓃴 𓃵 𓃶 𓃷 𓃸 𓃹 𓃺 𓃻 𓃼 𓃽 𓃾 𓃿 𓄀 𓄁 𓄂 𓄃 𓄄 𓄅 𓄆 𓄇\n", 809);
    write(1, "Original: 𓄿 𓅀 𓅁 𓅂 𓅃 𓅄 𓅅 𓅆 𓅇 𓅈 𓅉 𓅊 𓅋 𓅌 𓅍 𓅎 𓅏 𓅐 𓅑 𓅒 𓅓 𓅔 𓅕 𓅖 𓅗 𓅘 𓅙 𓅚 𓅛 𓅜 𓅝 𓅞 𓅟 𓅠 𓅡 𓅢 𓅣 𓅤 𓅥 𓅦 𓅧 𓅨 𓅩 𓅪 𓅫 𓅬 𓅭 𓅮 𓅯 𓅰 𓅱 𓅲 𓅳 𓅴 𓅵 𓅶 𓅷 𓅸 𓅹 𓅺 𓅻 𓅼 𓅽 𓅾 𓅿 𓆀 𓆁 𓆂 𓆃 𓆄 𓆅 𓆆 𓆇 𓆈 𓆉 𓆊 𓆋 𓆌 𓆍 𓆎 𓆏 𓆐 𓆑 𓆒 𓆓 𓆔 𓆕 𓆖 𓆗 𓆘 𓆙 𓆚 𓆛 𓆜 𓆝 𓆞 𓆟 𓆠 𓆡 𓆢 𓆣 𓆤 𓆥 𓆦 𓆧 𓆨𓆲𓃒 𓃓 𓃔 𓃕 𓃖 𓃗 𓃘 𓃙 𓃚 𓃛 𓃜 𓃝 𓃞 𓃟 𓃠 𓃡 𓃢 𓃣 𓃤 𓃥 𓃦 𓃧 𓃨 𓃩 𓃪 𓃫 𓃬 𓃭 𓃮 𓃯 𓃰 𓃱 𓃲 𓃳 𓃴 𓃵 𓃶 𓃷 𓃸 𓃹 𓃺 𓃻 𓃼 𓃽 𓃾 𓃿 𓄀 𓄁 𓄂 𓄃 𓄄 𓄅 𓄆 𓄇\n", 814);
    printf("---------------------------------------------------\n");
    ft_write(1, "Mio: ∞ Σ √ ∛ ∜ ∫ ∬ ∭ ∮ ∯ ∰ ∱ ∲ ∳ ∀ ∁ ∂ ∃ ∄ ∅ ∆ ∇ ∈ ∉ ∊ ∋ ∌ ∍ ∎ ∏ ∐ \n", 130);
    write(1, "Original: ∞ Σ √ ∛ ∜ ∫ ∬ ∭ ∮ ∯ ∰ ∱ ∲ ∳ ∀ ∁ ∂ ∃ ∄ ∅ ∆ ∇ ∈ ∉ ∊ ∋ ∌ ∍ ∎ ∏ ∐ \n", 135);
    printf("---------------------------------------------------\n");
    ft_write(1, "\nMio:\n", 7);
    if (ft_write(-1, "Hola Mundo\n", 12)) {
        printf("El file descriptor no es valido\n");
    }
    printf("---------------------------------------------------\n");
    ft_write(1, "\nOriginal:\n", 12);
    if (write(-1, "Hola Mundo\n", 12)) {
        printf("El file descriptor no es valido\n");
    }
    printf("---------------------------------------------------\n");

    printf("\nTest: ==> ft_read\n");
    printf("Mio:\n");
    ret = ft_read(0, buffer, sizeof(buffer) - 1);
    if (ret == -1) {
        perror("ft_read");
    } else {
        buffer[ret] = '\0';
        printf("Leído desde stdin: %s\n", buffer);
    }
    printf("---------------------------------------------------\n");
    int fd = open("archivo.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    ret = ft_read(fd, buffer, sizeof(buffer) - 1);
    if (ret == -1) {
        perror("ft_read");
    } else {
        buffer[ret] = '\0';
        printf("Leído desde archivo.txt: %s\n", buffer);
    }
    close(fd);
    printf("---------------------------------------------------\n");
    ret = ft_read(-1, buffer, sizeof(buffer));
    if (ret == -1) {
        perror("errno");
    }
    printf("---------------------------------------------------\n");
    printf("\nOriginal:\n");
    ret = read(0, buffer, sizeof(buffer) - 1);
    if (ret == -1) {
        perror("read");
    } else {
        buffer[ret] = '\0';
        printf("Leído desde stdin: %s\n", buffer);
    }
    printf("---------------------------------------------------\n");
    fd = open("archivo.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    ret = read(fd, buffer, sizeof(buffer) - 1);
    if (ret == -1) {
        perror("read");
    } else {
        buffer[ret] = '\0';
        printf("Leído desde archivo.txt: %s\n", buffer);
    }
    close(fd);
    printf("---------------------------------------------------\n");
    ret = read(-1, buffer, sizeof(buffer));
    if (ret == -1) {
        perror("errno");
    }
    printf("---------------------------------------------------\n");
    printf("\nTest: ==> ft_strdup\n");
    strdup_test("Hola mundo");
    strdup_test("");
    strdup_test("Texto con caracteres especiales: \t\n\r\x7F");
    strdup_test("Una cadena bastante larga que debería ocupar más espacio en la memoria que una corta.");
    strdup_test("🙂🚀✨");

    return 0;
}