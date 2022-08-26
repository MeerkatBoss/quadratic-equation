/**
 * @file text_styles.h
 * @author MeerkatBoss
 * @brief Contains color styles for text
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TEXT_STYLES_H
#define TEXT_STYLES_H

#define TEXT_BOLD "\033[1m"
#define TEXT_RESET "\033[0m"

#define TEXT_RED "\033[0;31m"
#define TEXT_GREEN "\033[0;32m"
#define TEXT_YELLOW "\033[0;33m"
#define TEXT_CYAN "\033[0;36m"

#define TEXT_ERROR(str) TEXT_BOLD TEXT_RED str TEXT_RESET
#define TEXT_WARNING(str) TEXT_BOLD TEXT_YELLOW str TEXT_RESET
#define TEXT_INFO(str) TEXT_BOLD TEXT_CYAN str TEXT_RESET
#define TEXT_SUCCESS(str) TEXT_BOLD TEXT_GREEN str TEXT_RESET

#define TEXT_GOOD(str) TEXT_GREEN str TEXT_RESET
#define TEXT_BAD(str) TEXT_RED str TEXT_RESET
#define TEXT_NOTE(str) TEXT_YELLOW str TEXT_RESET

#endif