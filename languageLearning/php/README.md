# PHP practice

I want to know more about this language for upcoming applications and job prospects,
plus it's basically the longest-standing web-focused language for back-end besides
Java.

## Requirements
PHP installed; can decide to either use "php" program or work with apache.

Working with apache, modify "conf" to point the document root to "src" in this
repo and enable PHP support (see [PHP manual documentation](https://www.php.net/manual/en/install.unix.apache2.php))

note for self on how my OS orders things from package installer:

/etc/httpd/ as root for pre-compiled modules
/etc/httpd/conf/ for conf files...
/etc/php/ as root for conf files, ini, and fpm (if desired)

## Running

PHP cli without apache (for quick tests):
```
php -f [filename]
```

Apache: just run your platform start script after modifying the httpd.conf.
