#!/usr/bin/perl
use strict;

my $dir     = $ARGV[0];
my $height  = $ARGV[1] ? $ARGV[1] : 200;
my $table   = "<tr>\n";
my $imgsrc  = '';
my $title   = '';
my $count   = 0;

opendir(DIRHANDLE, $dir);
foreach (readdir(DIRHANDLE)) {
    next if /^\.{1,2}$/;
    $imgsrc .= !$count ? "<img id=\"image$count\" class=\"image\" src=\"../$dir/$_\" height=\"$height\">\n" : "<img id=\"image$count\" class=\"image\" src=\"../$dir/$_\" height=\"$height\" style=\"display: none\">\n";
    $_       =~ s/^th_(.+)\..+$/$1/g;
    $table  .= "<td id=\"cell$count\">$_</td>\n";
    $title  .= !$count ? "<div id=\"title$count\" class=\"title\">$_</div>\n" : "<div id=\"title$count\" class=\"title\" style=\"display: none\">$_</div>\n";
    $table  .= "</tr>\n" if ++$count%5 == 0;
}

$table .= "</tr>\n";
closedir(DIRHANDLE);

open(TEMPLATE, "< ./src/bingo.inc");
my @INDATA = <TEMPLATE>;
close(TEMPLATE);

open(HTML, "> ./src/bingo.html");
foreach (@INDATA) {
    $_ =~ s/^\$TABLE$/$table/g;
    $_ =~ s/^\$IMGSRC$/$imgsrc/g;
    $_ =~ s/^\$TITLE$/$title/g;
    $_ =~ s/^\$LISTMAX,$/    listMax = $count,/g;
    print HTML $_;
}
close(HTML);
