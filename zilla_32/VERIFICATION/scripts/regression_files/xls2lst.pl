#!/usr/bin/perl 

use strict;
use warnings;

my $output_file_name = "testfile.lst";

if(@ARGV < 1)
{ 
    die "USAGE: perl $0 <xls file>\nScript aborted"; 
} 

open(my $FILE1, '<', $ARGV[0]) or die "Cannot open file  '$ARGV[0]'\n";

my @lines = <$FILE1>;

close $FILE1;

my @commands;

foreach (1..$#lines)
{
    my $line = $lines[$_];
    my ($test_name, $test_type, $priority, $times) = split(",", $line);
    if ($test_type =~ m/(UVM)|(C_TEST)/i)
    {
        $test_type = ($test_type =~ m"UVM")?"--uvm_test":""; 
    }
    else
    {
        die "Test type not supported at Row $_ of xls file\n";
    }
    push @commands, "$test_name $test_type, $priority:$times";

}

my @sorted_commands = sort {
    my ($priority_vala) = $a =~ /(\d+):/;
    my ($priority_valb) = $b =~ /(\d+):/;
    $priority_valb <=> $priority_vala;
} @commands;

my @prioritized_commands;

foreach my $line (@sorted_commands)
{
    $line =~ s/\s*(\d+)://;
    push @prioritized_commands, $line;
}

open (my $FILE2, "+>$output_file_name");

foreach my $line (@prioritized_commands)
{
    my ($final_command, $num) = split (",", $line);
    $final_command =~ s/\s*(.*)\s*/$1/g;
    for (1..$num)
    {
        print $FILE2 "$final_command\n";
    }
}
close $FILE2;
