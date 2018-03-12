/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:23:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/03/12 20:23:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <QApplication>
#include <QWidget>

int		main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QWidget wgt;
	wgt.setWindowTitle(QObject::tr("Hello world"));

	wgt.show();
	return (app.exec());
}
