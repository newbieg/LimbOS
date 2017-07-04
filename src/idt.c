// following this tutorial section on IDT http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html
//

#include <system.h>
#include <idt.h>
#include <tty.h>

isr_t interrupt_handlers[256];


extern void idt_flush(unsigned int);

void init_idt();
void idt_set_gate(unsigned char, unsigned int, unsigned short, unsigned char);

struct idt_entry idt[256];
struct idt_ptr idtpr;

void idt_install()
{
	idtpr.limit = sizeof(struct idt_entry) * 256 -1;
	idtpr.base = (unsigned int) & idt;
	memset((char*) &idt, 0, sizeof(struct idt_entry) * 256);

	out_b(0x20, 0x11);
	out_b(0xA0, 0x11);
	out_b(0x21, 0x20);
	out_b(0xA1, 0x28);
	out_b(0x21, 0x04);
	out_b(0xA1, 0x02);
	out_b(0x21, 0x01);
	out_b(0xA1, 0x01);
	out_b(0x21, 0x0);
	out_b(0xA1, 0x0);

	idt_set_gate(0, (unsigned int) isr0, 0x08, 0x8E);
	idt_set_gate(1, (unsigned int) isr1, 0x08, 0x8E);
	idt_set_gate(2, (unsigned int) isr2, 0x08, 0x8E);
	idt_set_gate(3, (unsigned int) isr3, 0x08, 0x8E);
	idt_set_gate(4, (unsigned int) isr4, 0x08, 0x8E);
	idt_set_gate(5, (unsigned int) isr5, 0x08, 0x8E);
	idt_set_gate(6, (unsigned int) isr6, 0x08, 0x8E);
	idt_set_gate(7, (unsigned int) isr7, 0x08, 0x8E);
	idt_set_gate(8, (unsigned int) isr8, 0x08, 0x8E);
	idt_set_gate(9, (unsigned int) isr9, 0x08, 0x8E);
	idt_set_gate(10, (unsigned int) isr10, 0x08, 0x8E);
	idt_set_gate(11, (unsigned int) isr11, 0x08, 0x8E);
	idt_set_gate(12, (unsigned int) isr12, 0x08, 0x8E);
	idt_set_gate(13, (unsigned int) isr13, 0x08, 0x8E);
	idt_set_gate(14, (unsigned int) isr14, 0x08, 0x8E);
	idt_set_gate(15, (unsigned int) isr15, 0x08, 0x8E);
	idt_set_gate(16, (unsigned int) isr16, 0x08, 0x8E);
	idt_set_gate(17, (unsigned int) isr17, 0x08, 0x8E);
	idt_set_gate(18, (unsigned int) isr18, 0x08, 0x8E);
	idt_set_gate(19, (unsigned int) isr19, 0x08, 0x8E);
	idt_set_gate(20, (unsigned int) isr20, 0x08, 0x8E);
	idt_set_gate(21, (unsigned int) isr21, 0x08, 0x8E);
	idt_set_gate(22, (unsigned int) isr22, 0x08, 0x8E);
	idt_set_gate(23, (unsigned int) isr23, 0x08, 0x8E);
	idt_set_gate(24, (unsigned int) isr24, 0x08, 0x8E);
	idt_set_gate(25, (unsigned int) isr25, 0x08, 0x8E);
	idt_set_gate(26, (unsigned int) isr26, 0x08, 0x8E);
	idt_set_gate(27, (unsigned int) isr27, 0x08, 0x8E);
	idt_set_gate(28, (unsigned int) isr28, 0x08, 0x8E);
	idt_set_gate(29, (unsigned int) isr29, 0x08, 0x8E);
	idt_set_gate(30, (unsigned int) isr30, 0x08, 0x8E);
	idt_set_gate(31, (unsigned int) isr31, 0x08, 0x8E);

	idt_set_gate(32, (unsigned int) irq0, 0x08, 0x8E);
	idt_set_gate(33, (unsigned int) irq1, 0x08, 0x8E);
	idt_set_gate(34, (unsigned int) irq2, 0x08, 0x8E);
	idt_set_gate(35, (unsigned int) irq3, 0x08, 0x8E);
	idt_set_gate(36, (unsigned int) irq4, 0x08, 0x8E);
	idt_set_gate(37, (unsigned int) irq5, 0x08, 0x8E);
	idt_set_gate(38, (unsigned int) irq6, 0x08, 0x8E);
	idt_set_gate(39, (unsigned int) irq7, 0x08, 0x8E);
	idt_set_gate(40, (unsigned int) irq8, 0x08, 0x8E);
	idt_set_gate(41, (unsigned int) irq9, 0x08, 0x8E);
	idt_set_gate(42, (unsigned int) irq10, 0x08, 0x8E);
	idt_set_gate(43, (unsigned int) irq11, 0x08, 0x8E);
	idt_set_gate(44, (unsigned int) irq12, 0x08, 0x8E);
	idt_set_gate(45, (unsigned int) irq13, 0x08, 0x8E);
	idt_set_gate(46, (unsigned int) irq14, 0x08, 0x8E);
	idt_set_gate(47, (unsigned int) irq15, 0x08, 0x8E);

	idt_set_gate(48, (unsigned int) isr48, 0x08, 0x8E);
	idt_set_gate(49, (unsigned int) isr49, 0x08, 0x8E);
	idt_set_gate(50, (unsigned int) isr50, 0x08, 0x8E);
	idt_set_gate(51, (unsigned int) isr51, 0x08, 0x8E);
	idt_set_gate(52, (unsigned int) isr52, 0x08, 0x8E);
	idt_set_gate(53, (unsigned int) isr53, 0x08, 0x8E);
	idt_set_gate(54, (unsigned int) isr54, 0x08, 0x8E);
	idt_set_gate(55, (unsigned int) isr55, 0x08, 0x8E);
	idt_set_gate(56, (unsigned int) isr56, 0x08, 0x8E);
	idt_set_gate(57, (unsigned int) isr57, 0x08, 0x8E);
	idt_set_gate(58, (unsigned int) isr58, 0x08, 0x8E);
	idt_set_gate(59, (unsigned int) isr59, 0x08, 0x8E);
	idt_set_gate(60, (unsigned int) isr60, 0x08, 0x8E);
	idt_set_gate(61, (unsigned int) isr61, 0x08, 0x8E);
	idt_set_gate(62, (unsigned int) isr62, 0x08, 0x8E);
	idt_set_gate(63, (unsigned int) isr63, 0x08, 0x8E);
	idt_set_gate(64, (unsigned int) isr64, 0x08, 0x8E);
	idt_set_gate(65, (unsigned int) isr65, 0x08, 0x8E);
	idt_set_gate(66, (unsigned int) isr66, 0x08, 0x8E);
	idt_set_gate(67, (unsigned int) isr67, 0x08, 0x8E);
	idt_set_gate(68, (unsigned int) isr68, 0x08, 0x8E);
	idt_set_gate(69, (unsigned int) isr69, 0x08, 0x8E);
	idt_set_gate(70, (unsigned int) isr70, 0x08, 0x8E);
	idt_set_gate(71, (unsigned int) isr71, 0x08, 0x8E);
	idt_set_gate(72, (unsigned int) isr72, 0x08, 0x8E);
	idt_set_gate(73, (unsigned int) isr73, 0x08, 0x8E);
	idt_set_gate(74, (unsigned int) isr74, 0x08, 0x8E);
	idt_set_gate(75, (unsigned int) isr75, 0x08, 0x8E);
	idt_set_gate(76, (unsigned int) isr76, 0x08, 0x8E);
	idt_set_gate(77, (unsigned int) isr77, 0x08, 0x8E);
	idt_set_gate(78, (unsigned int) isr78, 0x08, 0x8E);
	idt_set_gate(79, (unsigned int) isr79, 0x08, 0x8E);
	idt_set_gate(80, (unsigned int) isr80, 0x08, 0x8E);
	idt_set_gate(81, (unsigned int) isr81, 0x08, 0x8E);
	idt_set_gate(82, (unsigned int) isr82, 0x08, 0x8E);
	idt_set_gate(83, (unsigned int) isr83, 0x08, 0x8E);
	idt_set_gate(84, (unsigned int) isr84, 0x08, 0x8E);
	idt_set_gate(85, (unsigned int) isr85, 0x08, 0x8E);
	idt_set_gate(86, (unsigned int) isr86, 0x08, 0x8E);
	idt_set_gate(87, (unsigned int) isr87, 0x08, 0x8E);
	idt_set_gate(88, (unsigned int) isr88, 0x08, 0x8E);
	idt_set_gate(89, (unsigned int) isr89, 0x08, 0x8E);
	idt_set_gate(90, (unsigned int) isr90, 0x08, 0x8E);
	idt_set_gate(91, (unsigned int) isr91, 0x08, 0x8E);
	idt_set_gate(92, (unsigned int) isr92, 0x08, 0x8E);
	idt_set_gate(93, (unsigned int) isr93, 0x08, 0x8E);
	idt_set_gate(94, (unsigned int) isr94, 0x08, 0x8E);
	idt_set_gate(95, (unsigned int) isr95, 0x08, 0x8E);
	idt_set_gate(96, (unsigned int) isr96, 0x08, 0x8E);
	idt_set_gate(97, (unsigned int) isr97, 0x08, 0x8E);
	idt_set_gate(98, (unsigned int) isr98, 0x08, 0x8E);
	idt_set_gate(99, (unsigned int) isr99, 0x08, 0x8E);
	idt_set_gate(100, (unsigned int) isr100, 0x08, 0x8E);
	idt_set_gate(101, (unsigned int) isr101, 0x08, 0x8E);
	idt_set_gate(102, (unsigned int) isr102, 0x08, 0x8E);
	idt_set_gate(103, (unsigned int) isr103, 0x08, 0x8E);
	idt_set_gate(104, (unsigned int) isr104, 0x08, 0x8E);
	idt_set_gate(105, (unsigned int) isr105, 0x08, 0x8E);
	idt_set_gate(106, (unsigned int) isr106, 0x08, 0x8E);
	idt_set_gate(107, (unsigned int) isr107, 0x08, 0x8E);
	idt_set_gate(108, (unsigned int) isr108, 0x08, 0x8E);
	idt_set_gate(109, (unsigned int) isr109, 0x08, 0x8E);
	idt_set_gate(110, (unsigned int) isr110, 0x08, 0x8E);
	idt_set_gate(111, (unsigned int) isr111, 0x08, 0x8E);
	idt_set_gate(112, (unsigned int) isr112, 0x08, 0x8E);
	idt_set_gate(113, (unsigned int) isr113, 0x08, 0x8E);
	idt_set_gate(114, (unsigned int) isr114, 0x08, 0x8E);
	idt_set_gate(115, (unsigned int) isr115, 0x08, 0x8E);
	idt_set_gate(116, (unsigned int) isr116, 0x08, 0x8E);
	idt_set_gate(117, (unsigned int) isr117, 0x08, 0x8E);
	idt_set_gate(118, (unsigned int) isr118, 0x08, 0x8E);
	idt_set_gate(119, (unsigned int) isr119, 0x08, 0x8E);
	idt_set_gate(120, (unsigned int) isr120, 0x08, 0x8E);
	idt_set_gate(121, (unsigned int) isr121, 0x08, 0x8E);
	idt_set_gate(122, (unsigned int) isr122, 0x08, 0x8E);
	idt_set_gate(123, (unsigned int) isr123, 0x08, 0x8E);
	idt_set_gate(124, (unsigned int) isr124, 0x08, 0x8E);
	idt_set_gate(125, (unsigned int) isr125, 0x08, 0x8E);
	idt_set_gate(126, (unsigned int) isr126, 0x08, 0x8E);
	idt_set_gate(127, (unsigned int) isr127, 0x08, 0x8E);
	idt_set_gate(128, (unsigned int) isr128, 0x08, 0x8E);
	idt_set_gate(129, (unsigned int) isr129, 0x08, 0x8E);
	idt_set_gate(130, (unsigned int) isr130, 0x08, 0x8E);
	idt_set_gate(131, (unsigned int) isr131, 0x08, 0x8E);
	idt_set_gate(132, (unsigned int) isr132, 0x08, 0x8E);
	idt_set_gate(133, (unsigned int) isr133, 0x08, 0x8E);
	idt_set_gate(134, (unsigned int) isr134, 0x08, 0x8E);
	idt_set_gate(135, (unsigned int) isr135, 0x08, 0x8E);
	idt_set_gate(136, (unsigned int) isr136, 0x08, 0x8E);
	idt_set_gate(137, (unsigned int) isr137, 0x08, 0x8E);
	idt_set_gate(138, (unsigned int) isr138, 0x08, 0x8E);
	idt_set_gate(139, (unsigned int) isr139, 0x08, 0x8E);
	idt_set_gate(140, (unsigned int) isr130, 0x08, 0x8E);
	idt_set_gate(141, (unsigned int) isr141, 0x08, 0x8E);
	idt_set_gate(142, (unsigned int) isr142, 0x08, 0x8E);
	idt_set_gate(143, (unsigned int) isr143, 0x08, 0x8E);
	idt_set_gate(144, (unsigned int) isr144, 0x08, 0x8E);
	idt_set_gate(145, (unsigned int) isr145, 0x08, 0x8E);
	idt_set_gate(146, (unsigned int) isr146, 0x08, 0x8E);
	idt_set_gate(147, (unsigned int) isr147, 0x08, 0x8E);
	idt_set_gate(148, (unsigned int) isr148, 0x08, 0x8E);
	idt_set_gate(149, (unsigned int) isr149, 0x08, 0x8E);
	idt_set_gate(150, (unsigned int) isr150, 0x08, 0x8E);
	idt_set_gate(151, (unsigned int) isr151, 0x08, 0x8E);
	idt_set_gate(152, (unsigned int) isr152, 0x08, 0x8E);
	idt_set_gate(153, (unsigned int) isr153, 0x08, 0x8E);
	idt_set_gate(154, (unsigned int) isr154, 0x08, 0x8E);
	idt_set_gate(155, (unsigned int) isr155, 0x08, 0x8E);
	idt_set_gate(156, (unsigned int) isr156, 0x08, 0x8E);
	idt_set_gate(157, (unsigned int) isr157, 0x08, 0x8E);
	idt_set_gate(158, (unsigned int) isr158, 0x08, 0x8E);
	idt_set_gate(159, (unsigned int) isr159, 0x08, 0x8E);
	idt_set_gate(160, (unsigned int) isr160, 0x08, 0x8E);
	idt_set_gate(161, (unsigned int) isr161, 0x08, 0x8E);
	idt_set_gate(162, (unsigned int) isr162, 0x08, 0x8E);
	idt_set_gate(163, (unsigned int) isr163, 0x08, 0x8E);
	idt_set_gate(164, (unsigned int) isr164, 0x08, 0x8E);
	idt_set_gate(165, (unsigned int) isr165, 0x08, 0x8E);
	idt_set_gate(166, (unsigned int) isr166, 0x08, 0x8E);
	idt_set_gate(167, (unsigned int) isr167, 0x08, 0x8E);
	idt_set_gate(168, (unsigned int) isr168, 0x08, 0x8E);
	idt_set_gate(169, (unsigned int) isr169, 0x08, 0x8E);
	idt_set_gate(170, (unsigned int) isr170, 0x08, 0x8E);
	idt_set_gate(171, (unsigned int) isr171, 0x08, 0x8E);
	idt_set_gate(172, (unsigned int) isr172, 0x08, 0x8E);
	idt_set_gate(173, (unsigned int) isr173, 0x08, 0x8E);
	idt_set_gate(174, (unsigned int) isr174, 0x08, 0x8E);
	idt_set_gate(175, (unsigned int) isr175, 0x08, 0x8E);
	idt_set_gate(176, (unsigned int) isr176, 0x08, 0x8E);
	idt_set_gate(177, (unsigned int) isr177, 0x08, 0x8E);
	idt_set_gate(178, (unsigned int) isr178, 0x08, 0x8E);
	idt_set_gate(179, (unsigned int) isr179, 0x08, 0x8E);
	idt_set_gate(180, (unsigned int) isr180, 0x08, 0x8E);
	idt_set_gate(181, (unsigned int) isr181, 0x08, 0x8E);
	idt_set_gate(182, (unsigned int) isr182, 0x08, 0x8E);
	idt_set_gate(183, (unsigned int) isr183, 0x08, 0x8E);
	idt_set_gate(184, (unsigned int) isr184, 0x08, 0x8E);
	idt_set_gate(185, (unsigned int) isr185, 0x08, 0x8E);
	idt_set_gate(186, (unsigned int) isr186, 0x08, 0x8E);
	idt_set_gate(187, (unsigned int) isr187, 0x08, 0x8E);
	idt_set_gate(188, (unsigned int) isr188, 0x08, 0x8E);
	idt_set_gate(189, (unsigned int) isr189, 0x08, 0x8E);
	idt_set_gate(190, (unsigned int) isr190, 0x08, 0x8E);
	idt_set_gate(191, (unsigned int) isr191, 0x08, 0x8E);
	idt_set_gate(192, (unsigned int) isr192, 0x08, 0x8E);
	idt_set_gate(193, (unsigned int) isr193, 0x08, 0x8E);
	idt_set_gate(194, (unsigned int) isr194, 0x08, 0x8E);
	idt_set_gate(195, (unsigned int) isr195, 0x08, 0x8E);
	idt_set_gate(196, (unsigned int) isr196, 0x08, 0x8E);
	idt_set_gate(197, (unsigned int) isr197, 0x08, 0x8E);
	idt_set_gate(198, (unsigned int) isr198, 0x08, 0x8E);
	idt_set_gate(199, (unsigned int) isr199, 0x08, 0x8E);
	idt_set_gate(200, (unsigned int) isr200, 0x08, 0x8E);
	idt_set_gate(201, (unsigned int) isr201, 0x08, 0x8E);
	idt_set_gate(202, (unsigned int) isr202, 0x08, 0x8E);
	idt_set_gate(203, (unsigned int) isr203, 0x08, 0x8E);
	idt_set_gate(204, (unsigned int) isr204, 0x08, 0x8E);
	idt_set_gate(205, (unsigned int) isr205, 0x08, 0x8E);
	idt_set_gate(206, (unsigned int) isr206, 0x08, 0x8E);
	idt_set_gate(207, (unsigned int) isr207, 0x08, 0x8E);
	idt_set_gate(208, (unsigned int) isr208, 0x08, 0x8E);
	idt_set_gate(209, (unsigned int) isr209, 0x08, 0x8E);
	idt_set_gate(210, (unsigned int) isr210, 0x08, 0x8E);
	idt_set_gate(211, (unsigned int) isr211, 0x08, 0x8E);
	idt_set_gate(212, (unsigned int) isr212, 0x08, 0x8E);
	idt_set_gate(213, (unsigned int) isr213, 0x08, 0x8E);
	idt_set_gate(214, (unsigned int) isr214, 0x08, 0x8E);
	idt_set_gate(215, (unsigned int) isr215, 0x08, 0x8E);
	idt_set_gate(216, (unsigned int) isr216, 0x08, 0x8E);
	idt_set_gate(217, (unsigned int) isr217, 0x08, 0x8E);
	idt_set_gate(218, (unsigned int) isr218, 0x08, 0x8E);
	idt_set_gate(219, (unsigned int) isr219, 0x08, 0x8E);
	idt_set_gate(220, (unsigned int) isr220, 0x08, 0x8E);
	idt_set_gate(221, (unsigned int) isr221, 0x08, 0x8E);
	idt_set_gate(222, (unsigned int) isr222, 0x08, 0x8E);
	idt_set_gate(223, (unsigned int) isr223, 0x08, 0x8E);
	idt_set_gate(224, (unsigned int) isr224, 0x08, 0x8E);
	idt_set_gate(225, (unsigned int) isr225, 0x08, 0x8E);
	idt_set_gate(226, (unsigned int) isr226, 0x08, 0x8E);
	idt_set_gate(227, (unsigned int) isr227, 0x08, 0x8E);
	idt_set_gate(228, (unsigned int) isr228, 0x08, 0x8E);
	idt_set_gate(229, (unsigned int) isr229, 0x08, 0x8E);
	idt_set_gate(230, (unsigned int) isr230, 0x08, 0x8E);
	idt_set_gate(231, (unsigned int) isr231, 0x08, 0x8E);
	idt_set_gate(232, (unsigned int) isr232, 0x08, 0x8E);
	idt_set_gate(233, (unsigned int) isr233, 0x08, 0x8E);
	idt_set_gate(234, (unsigned int) isr234, 0x08, 0x8E);
	idt_set_gate(235, (unsigned int) isr235, 0x08, 0x8E);
	idt_set_gate(236, (unsigned int) isr236, 0x08, 0x8E);
	idt_set_gate(237, (unsigned int) isr237, 0x08, 0x8E);
	idt_set_gate(238, (unsigned int) isr238, 0x08, 0x8E);
	idt_set_gate(239, (unsigned int) isr239, 0x08, 0x8E);
	idt_set_gate(240, (unsigned int) isr240, 0x08, 0x8E);
	idt_set_gate(241, (unsigned int) isr241, 0x08, 0x8E);
	idt_set_gate(242, (unsigned int) isr242, 0x08, 0x8E);
	idt_set_gate(243, (unsigned int) isr243, 0x08, 0x8E);
	idt_set_gate(244, (unsigned int) isr244, 0x08, 0x8E);
	idt_set_gate(245, (unsigned int) isr245, 0x08, 0x8E);
	idt_set_gate(246, (unsigned int) isr246, 0x08, 0x8E);
	idt_set_gate(247, (unsigned int) isr247, 0x08, 0x8E);
	idt_set_gate(248, (unsigned int) isr248, 0x08, 0x8E);
	idt_set_gate(249, (unsigned int) isr249, 0x08, 0x8E);
	idt_set_gate(250, (unsigned int) isr250, 0x08, 0x8E);
	idt_set_gate(251, (unsigned int) isr251, 0x08, 0x8E);
	idt_set_gate(252, (unsigned int) isr252, 0x08, 0x8E);
	idt_set_gate(253, (unsigned int) isr253, 0x08, 0x8E);
	idt_set_gate(254, (unsigned int) isr254, 0x08, 0x8E);
	idt_set_gate(255, (unsigned int) isr255, 0x08, 0x8E);

	idt_flush((unsigned int) &idtpr);
}

void idt_set_gate(unsigned char num, unsigned int base, unsigned short sel, unsigned char flags)
{
	idt[num].base_low = base & 0xFFFF;
	idt[num].base_high = (base >> 16) & 0xFFFF;
	idt[num].sellector = sel;
	idt[num].zero = 0;
	idt[num].flags = flags | 0x60;
}



// This doesn't do much at the moment, but at least it reports the isr and exceptions...
void isr_handler(registers_t reg )
{
	vga_writeString("\nInterupt Recieved: #");
	vga_writeDec(reg.int_no);
//	vga_putchar('\n');
	vga_writeString(" Error_code: ");
	vga_writeDec(reg.err_code);
	vga_putchar('\n');
	vga_writeString("REGISTERS");
	vga_writeString("\nds:");
	vga_writeDec(reg.ds);
//	vga_putchar('\n');
	vga_writeString(" edi:");
	vga_writeDec(reg.edi);
//	vga_putchar('\n');
	vga_writeString(" esi:");
	vga_writeDec(reg.esi);
//	vga_putchar('\n');
	vga_writeString(" ebp:");
	vga_writeDec(reg.ebp);
//	vga_putchar('\n');
	vga_writeString(" esp:");
	vga_writeDec(reg.esp);
//	vga_putchar('\n');
	vga_writeString(" ebx:");
	vga_writeDec(reg.ebx);
//	vga_putchar('\n');
	vga_writeString(" edx:");
	vga_writeDec(reg.edx);
//	vga_putchar('\n');
	vga_writeString(" ecx:");
	vga_writeDec(reg.ecx);
//	vga_putchar('\n');
	vga_writeString(" eax:");
	vga_writeDec(reg.eax);
	vga_putchar('\n');
//	halt();

}


void irq_handler(registers_t reg)
{
	if(reg.int_no >= 40)
	{
		out_b(0xA0, 0x20);
	}
	out_b(0x20, 0x20);

	if(interrupt_handlers[reg.int_no] != 0)
	{
		isr_t handler = interrupt_handlers[reg.int_no];
		handler(reg);
	}
}

void register_interrupt_handler(unsigned char n, isr_t handler)
{
	interrupt_handlers[n] = handler;
}





