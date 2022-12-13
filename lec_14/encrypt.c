/**
 *
 * What is Caesar Cipher?
 * It is one of the simplest encryption technique in which each character in plain text is replaced by a character some fixed number of positions down to it.
 * For example, if key is 3 then we have to replace character by another character that is 3 position down to it. Like A will be replaced by D, C will be replaced by F and so on.
 * For decryption just follow the reverse of encryption process.
 *
 * https://www.thecrazyprogrammer.com/2016/11/caesar-cipher-c-c-encryption-decryption.html
 */

#include <stdio.h>

int main()
{
    char message[100], ch;
    int i, key;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    for (i = 0; message[i] != '\0'; ++i)
    {
        // hello
        // h = 104
        ch = message[i];
        printf("26: ch=%d\n", ch);
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            printf("30: ch=%d\n", ch);
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
                printf("34: ch=%d\n", ch);
            }
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    printf("Encrypted message: %s", message);
    return 0;
}