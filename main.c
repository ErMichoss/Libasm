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


void ft_strdup_test(void)
{
	char const *tests[] = {
		"Hello, World!",
		"a",
		"",
		"\t\v\t\v\a\b\33\1",
		"\0\0\0\0\0",
		"😀",
		"😀\r\t\00\000🐀🐀🐀🐀🐀🐀\v\v\v\r\r\n\\n\n🐀",
		"𝔊𝔬𝔱𝔥𝔦𝔠",
		"oldɯǝɾǝ un sǝ ǝʇsǝ",
		"⠞⠓⠊⠎⠀⠊⠎⠀⠁⠝⠀⠑⠭⠁⠍⠏⠇⠑",
		NULL
	};

	char *og_strdup, *my_strdup;
	int fd, i;

	printf("Tests from %s:\n", __func__);
	for (i = 0; tests[i] != NULL; i++) {
		og_strdup = strdup(tests[i]);
		my_strdup = ft_strdup(tests[i]);

		if (strlen(og_strdup) != strlen(my_strdup))
			fd = 2;
		else if (strcmp(og_strdup, my_strdup) != 0)
			fd = 2;
		else
			fd = 1;

		printf("%2d: expected %s, received %s\n", i, og_strdup, my_strdup);

		free(og_strdup);
		free(my_strdup);
	}
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
    STRLEN("abcd");
    STRLEN("ABCDEFG");
    STRLEN("0123456789abcdef");
    STRLEN("42");
    STRLEN("1");
    printf("\nTest: ==> ft_strcmp\n");

    STRCMP("", "");
    STRCMP("abcd", "abcd");
    STRCMP("abcd", "abce");
    STRCMP("abcd", "abcefgh");
    STRCMP("", "abcd");
    STRCMP("abcd", "");

    printf("\nTest: ==> ft_strcpy\n");
    printf("`%s` (`abcd`)\n", ft_strcpy(buffer, "abcd"));
	printf("`%s` (empty)\n", ft_strcpy(buffer, ""));
	printf("`%s` (`long message`)\n", ft_strcpy(buffer, "long message"));

    printf("\nTest: ==> ft_write\n");
    printf("Mine: ", ft_write(1, "hi\n", 3));
    printf("Original:" ); write(1, "hi\n", 3);
    printf("Mine: "); ft_write(1, "𓄿 𓅀 𓅁 𓅂 𓅃 𓅄 𓅅 𓅆 𓅇 𓅈 𓅉 𓅊 𓅋 𓅌 𓅍 𓅎 𓅏 𓅐 𓅑 𓅒 𓅓 𓅔 𓅕 𓅖 𓅗 𓅘 𓅙 𓅚 𓅛 𓅜 𓅝 𓅞 𓅟 𓅠 𓅡 𓅢 𓅣 𓅤 𓅥 𓅦 𓅧 𓅨 𓅩 𓅪 𓅫 𓅬 𓅭 𓅮 𓅯 𓅰 𓅱 𓅲 𓅳 𓅴 𓅵 𓅶 𓅷 𓅸 𓅹 𓅺 𓅻 𓅼 𓅽 𓅾 𓅿 𓆀 𓆁 𓆂 𓆃 𓆄 𓆅 𓆆 𓆇 𓆈 𓆉 𓆊 𓆋 𓆌 𓆍 𓆎 𓆏 𓆐 𓆑 𓆒 𓆓 𓆔 𓆕 𓆖 𓆗 𓆘 𓆙 𓆚 𓆛 𓆜 𓆝 𓆞 𓆟 𓆠 𓆡 𓆢 𓆣 𓆤 𓆥 𓆦 𓆧 𓆨𓆲𓃒 𓃓 𓃔 𓃕 𓃖 𓃗 𓃘 𓃙 𓃚 𓃛 𓃜 𓃝 𓃞 𓃟 𓃠 𓃡 𓃢 𓃣 𓃤 𓃥 𓃦 𓃧 𓃨 𓃩 𓃪 𓃫 𓃬 𓃭 𓃮 𓃯 𓃰 𓃱 𓃲 𓃳 𓃴 𓃵 𓃶 𓃷 𓃸 𓃹 𓃺 𓃻 𓃼 𓃽 𓃾 𓃿 𓄀 𓄁 𓄂 𓄃 𓄄 𓄅 𓄆 𓄇\n", 804);
    printf("Original: "); write(1, "𓄿 𓅀 𓅁 𓅂 𓅃 𓅄 𓅅 𓅆 𓅇 𓅈 𓅉 𓅊 𓅋 𓅌 𓅍 𓅎 𓅏 𓅐 𓅑 𓅒 𓅓 𓅔 𓅕 𓅖 𓅗 𓅘 𓅙 𓅚 𓅛 𓅜 𓅝 𓅞 𓅟 𓅠 𓅡 𓅢 𓅣 𓅤 𓅥 𓅦 𓅧 𓅨 𓅩 𓅪 𓅫 𓅬 𓅭 𓅮 𓅯 𓅰 𓅱 𓅲 𓅳 𓅴 𓅵 𓅶 𓅷 𓅸 𓅹 𓅺 𓅻 𓅼 𓅽 𓅾 𓅿 𓆀 𓆁 𓆂 𓆃 𓆄 𓆅 𓆆 𓆇 𓆈 𓆉 𓆊 𓆋 𓆌 𓆍 𓆎 𓆏 𓆐 𓆑 𓆒 𓆓 𓆔 𓆕 𓆖 𓆗 𓆘 𓆙 𓆚 𓆛 𓆜 𓆝 𓆞 𓆟 𓆠 𓆡 𓆢 𓆣 𓆤 𓆥 𓆦 𓆧 𓆨𓆲𓃒 𓃓 𓃔 𓃕 𓃖 𓃗 𓃘 𓃙 𓃚 𓃛 𓃜 𓃝 𓃞 𓃟 𓃠 𓃡 𓃢 𓃣 𓃤 𓃥 𓃦 𓃧 𓃨 𓃩 𓃪 𓃫 𓃬 𓃭 𓃮 𓃯 𓃰 𓃱 𓃲 𓃳 𓃴 𓃵 𓃶 𓃷 𓃸 𓃹 𓃺 𓃻 𓃼 𓃽 𓃾 𓃿 𓄀 𓄁 𓄂 𓄃 𓄄 𓄅 𓄆 𓄇\n", 804);
    printf("Mine: "); ft_write(1, " ∞ Σ √ ∛ ∜ ∫ ∬ ∭ ∮ ∯ ∰ ∱ ∲ ∳ ∀ ∁ ∂ ∃ ∄ ∅ ∆ ∇ ∈ ∉ ∊ ∋ ∌ ∍ ∎ ∏ ∐ \n", 126);
    printf("Original: "); write(1, " ∞ Σ √ ∛ ∜ ∫ ∬ ∭ ∮ ∯ ∰ ∱ ∲ ∳ ∀ ∁ ∂ ∃ ∄ ∅ ∆ ∇ ∈ ∉ ∊ ∋ ∌ ∍ ∎ ∏ ∐ \n", 126);

    printf("\nTest: ==> ft_read\n");
    ret = ft_read(0, buffer, sizeof(buffer) - 1);
    if (ret == -1) {
        perror("ft_read");
    } else {
        buffer[ret] = '\0';
        printf("Leído desde stdin: %s\n", buffer);
    }
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
    ret = ft_read(999, buffer, sizeof(buffer));
    if (ret == -1) {
        perror("ft_read con fd inválido");
    }

    printf("\nTest: ==> ft_strdup\n");

    return 0;
}