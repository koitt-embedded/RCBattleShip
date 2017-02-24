#!/usr/bin/perl -sw

my $input_file  = $ARGV[0];
my $output_file = $ARGV[1];
open( my $fh_in, '<',  $input_file ) or die "Can't open $input_file: $!";
open( my $fh_out, '>', $output_file);

while ( my $line = <$fh_in> ) {
    if ( $line =~ /blis_/ ) {
        print $fh_out $line;
    }
}

close $fh_in;
close $fh_out